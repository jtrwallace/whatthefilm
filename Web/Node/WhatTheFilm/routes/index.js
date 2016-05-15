var express = require('express');

module.exports = (function() {
  'use strict';
  var router = express.Router();

  router.get('/', function(req, res, next) {
    res.render('index', { title: 'Express'});
  });

  return router;
})();





/*
var router = express.Router();

/!* GET home page. *!/
router.get('/', function(req, res, next) {
  res.render('index', { title: 'Express'});
});

module.exports = router;
*/
