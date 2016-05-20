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

    this.specificFilm = function(id, res) {
        connection.acquire(function(err, con) {
            con.query('select * from films where id = ?', [id], function(err, result) {
                con.release();
                var single = result[0];
                res.send(single);
            })
        });
    };

    this.categories = function(res) {
        connection.acquire(function(err, con) {
           con.query('select distinct(category) from films', function(err, result) {
               con.release();
               var categories = [];
               result.forEach(function (item) {
                   categories.push(item.category);
               });
               res.send(categories);
           })
        });
    };

    this.specificCategory = function(category, res) {
        connection.acquire(function(err, con) {
            con.query('select * from films where category = ?', [category], function(err, result) {
                con.release();
                res.send(result);
            })
        });
    };


    this.genres = function(res) {
        connection.acquire(function(err, con) {
            con.query('select distinct(genre) from films', function(err, result) {
                con.release();
                var genres = [];
                result.forEach(function (item) {
                    genres.push(item.genre);
                });
                res.send(genres);
            })
        });
    };

    this.specificGenre = function(genre, res) {
        connection.acquire(function(err, con) {
            con.query('select * from films where genre = ?', [genre], function(err, result) {
                con.release();
                res.send(result);
            })
        });
    };

    this.getMaxID = function(res) {
        connection.acquire(function(err, con) {
            con.query('SELECT * FROM films ORDER BY id DESC LIMIT 0, 1', function(err, result) {
                con.release();
                console.log(result[0]);
                res.send(result[0]);
            })
        });
    };

}
module.exports = new Films();