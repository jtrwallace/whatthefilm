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

    return api;
})();
