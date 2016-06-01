var express = require('express');

module.exports = (function() {
  'use strict';
  var router = express.Router();
  var connection = require('../connection');

  router.get('/', function(req, res) {
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
          res.render('index', { films: filmsResult, features: featured });
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

