var connection = require('../connection');

function Films() {

    this.get = function(res) {
        connection.acquire(function(err, con) {
            con.query('select * from films', function(err, result) {
                con.release();
                res.send(result);
            });
        });
    };

    this.create = function(film, res) {
        connection.acquire(function(err, con) {
            con.query('insert into films set ?', film, function(err, result) {
                con.release();
                if (err) {
                    res.send({status: 1, message: 'Film creation failed'});
                } else {
                    res.send({status: 0, message: 'Film created successfully'});
                }
            });
        });
    };

    this.update = function(film, res) {
        connection.acquire(function(err, con) {
            con.query('update films set ? where id = ?', [film, film.id], function(err, result) {
                con.release();
                if (err) {
                    res.send({status: 1, message: 'Film update failed'});
                } else {
                    res.send({status: 0, message: 'Film updated successfully'});
                }
            });
        });
    };

    this.delete = function(id, res) {
        connection.acquire(function(err, con) {
            con.query('delete from films where id = ?', [id], function(err, result) {
                con.release();
                if (err) {
                    res.send({status: 1, message: 'Failed to delete'});
                } else {
                    res.send({status: 0, message: 'Deleted successfully'});
                }
            });
        });
    };
}
module.exports = new Films();