var mysql = require('mysql');
var config = require ('./config');

function Connection() {
    this.pool = null;

    this.init = function() {
        this.pool = mysql.createPool({
            connectionLimit: 100,
            host     : config.db.host,
            user     : config.db.user,
            password : config.db.password,
            port     : config.db.port,
            database : config.db.database
        });
    };

    this.acquire = function(callback) {
        console.log("In connection.acquire");
        this.pool.getConnection(function(err, connection) {
            callback(err, connection);
        });
    };
}

module.exports = new Connection();