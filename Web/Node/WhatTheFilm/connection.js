var mysql = require('mysql');

function Connection() {
    this.pool = null;

    this.init = function() {
        this.pool = mysql.createPool({
            connectionLimit: 10,
            host     : 'whatthefilm.conwyalntrrd.us-west-1.rds.amazonaws.com',
            user     : 'whatthefilm',
            password : 'sC6gx4Pis7mm',
            port     : '3306',
            database : 'whatthefilm'
        });
    };

    this.acquire = function(callback) {
        this.pool.getConnection(function(err, connection) {
            callback(err, connection);
        });
    };
}

module.exports = new Connection();