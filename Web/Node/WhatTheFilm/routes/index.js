var express = require('express');

module.exports = (function() {
  'use strict';
  var router = express.Router();
  var connection = require('../connection');

  router.get('/', function(req, res) {
    connection.acquire(function(err, con) {
      con.query('select * from films', function(err, filmsResult) {
        con.query('select * from featured', function(err, featuresResult) {
          var featured = [];
          featuresResult.forEach(function(feature) {
            var combo = {
              "feature": feature,
              "film": filmsResult.filter(function(film) {
                return film.id == feature['film_id'];
              })[0]
            };
            featured.push(combo);
          });

          con.query('select distinct(name) from genres', function(err, genresResult) {
            var genres = [];
            genresResult.forEach(function (item) {
              genres.push(item.name);
            });
            var object = {};
            var doneCount = 0;
            for (var i = 0; i < genres.length; i++) {
              (function (i) {
                con.query('SELECT distinct f.* from films f join genres_films gf on f.id = gf.filmID join genres g on gf.genreID = g.id where g.name = ?', [genres[i]], function (err, specGenreResult) {
                  object[genres[i]] = specGenreResult;
                  ++doneCount;
                  if (doneCount >= genres.length) {
                    con.release();
                    res.render('index', { films: filmsResult, features: featured, genres: object, genrelist: genres });
                  }
                });
              })(i);
            }
          });
        });
      });
    });
  });
  
  router.get('/data/', function(req, res) {
    connection.acquire(function(err, con) {
      con.query('select * from films', function(err, filmsResult) {
        con.query('select * from featured', function(err, featuresResult) {
          con.release();
          var featured = [];
          featuresResult.forEach(function(feature) {
            var combo = {
              "feature": feature,
              "film": filmsResult.filter(function(film) {
                return film.id == feature['film_id'];
              })[0]
            };
            featured.push(combo);
          });
          res.render('data', { films: filmsResult, features: featured });
        });
      });
    });
  });

  return router;
})();

