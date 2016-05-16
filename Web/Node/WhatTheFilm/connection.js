var mysql = require('mysql');

function Connection() {
    this.pool = null;

    this.init = function() {
        this.pool = mysql.createPool({
            connectionLimit: 100,
            host     : process.env.RDS_HOSTNAME,
            user     : process.env.RDS_USERNAME,
            password : process.env.RDS_PASSWORD,
            port     : process.env.RDS_PORT,
            database : process.env.RDS_DATABASE
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