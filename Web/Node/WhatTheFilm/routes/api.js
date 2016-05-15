var express = require('express');

module.exports = (function() {
    'use strict';
    var api = express.Router();
    var films = require('../models/films');

    api.get('/films/', function(req, res, next) {
        console.log("In GET /films/");
        films.get(res);
    });

    /* POST new film to database. */
    api.post('/films/', function(req, res, next) {
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


/*var router = express.Router();
var films = require('../models/films');

/!* GET list of all films. *!/
router.get('/api/films/', function(req, res, next) {
    console.log("In GET /films/");
    films.get(res);
});

/!* POST new film to database. *!/
router.post('/api/films/', function(req, res, next) {
    films.create(req.body, res);
});

/!* PUT an update to a film. *!/
router.put('/api/films/', function(req, res) {
    films.update(req.body, res);
});

/!* DELETE a film based on id. *!/
router.delete('/api/films/:id/', function(req, res) {
    films.delete(req.params.id, res);
});*/

// module.exports = router;