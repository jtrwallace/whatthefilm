var express = require('express');

module.exports = (function() {
    'use strict';
    var api = express.Router();
    var films = require('../models/films');

    api.get('/films/', function(req, res) {
        films.get(res);
    });

    /* POST new film to database. */
    api.post('/films/', function(req, res) {
        films.create(req.body, res);
    });

    /* PUT an update to a film. */
    api.put('/films/', function(req, res) {
        films.update(req.body, res);
    });

    /* DELETE a film based on id. */
    api.delete('/films/:id/', function(req, res) {
        films.delete(req.params.id, res);
    });

    api.get('/films/:id/', function(req, res) {
        films.specificFilm(req.params.id, res);
    });

    api.get('/categories/', function(req, res) {
        films.categories(res);
    });

    api.get('/categories/:category', function(req, res) {
        films.specificCategory(req.params.category, res);
    });

    api.get('/genres/', function(req, res) {
        films.genres(res);
    });

    api.get('/genres/:genre', function(req, res) {
        films.specificGenre(req.params.genre, res);
    });

    api.get('/maxid/', function(req, res) {
        films.getMaxID(res);
    });

    api.get('/featured_maxid/', function(req, res) {
        films.getFeaturedMaxID(res);
    });

    api.get('/search/:query', function(req, res) {
        films.search(req.params.query, res);
    });

    api.get('/featured/', function(req, res) {
        films.getFeatured(res);
    });

    api.get('/featured/:id', function(req, res) {
        films.specificFeature(req.params.id, res);
    });

    api.post('/featured/', function(req, res) {
        films.createFeatured(req.body, res);
    });

    api.put('/featured/', function(req, res) {
        films.updateFeatured(req.body, res);
    });

    api.delete('/featured/:id/', function(req, res) {
        films.deleteFeatured(req.params.id, res);
    });

    return api;
})();
