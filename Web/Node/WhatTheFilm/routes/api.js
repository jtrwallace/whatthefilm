var express = require('express');

module.exports = (function() {
    'use strict';
    var api = express.Router();
    var films = require('../models/films');

    api.get('/films/', function(req, res) {
        console.log("In GET /api/films/");
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

    return api;
})();
