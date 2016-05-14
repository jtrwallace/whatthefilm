var express = require('express');
var router = express.Router();
var films = require('../models/films');

/* GET home page. */
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express'});
});

/* GET list of all films. */
router.get('/films/', function(req, res, next) {
  films.get(res);
});

/* POST new film to database. */
router.post('/films/', function(req, res, next) {
  films.create(req.body, res);
});

/* PUT an update to a film. */
router.put('/films/', function(req, res) {
  films.update(req.body, res);
});

/* DELETE a film based on id. */
router.delete('/films/:id/', function(req, res) {
  films.delete(req.params.id, res);
});

module.exports = router;
