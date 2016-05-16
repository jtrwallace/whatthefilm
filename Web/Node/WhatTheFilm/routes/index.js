var express = require('express');

module.exports = (function() {
  'use strict';
  var router = express.Router();
  var connection = require('../connection');

  router.get('/', function(req, res) {
    connection.acquire(function(err, con) {
      con.query('select * from films', function(err, result) {
        con.release();
        console.log(result);
        console.log(JSON.stringify(result));
        res.render('index', { films: result});
      });
    });

  });

  return router;
})();

