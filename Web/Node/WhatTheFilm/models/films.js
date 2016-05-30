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
                res.send(result[0]);
            })
        });
    };

    this.getFeaturedMaxID = function(res) {
        connection.acquire(function(err, con) {
            con.query('SELECT * FROM featured ORDER BY id DESC LIMIT 0, 1', function(err, result) {
                con.release();
                res.send(result[0]);
            })
        });
    };

    this.search = function(query, res) {
        connection.acquire(function(err, con) {
            con.query('select * from films where title sounds like "%' + [query] + '%"', function(err, titleResult) {
                con.query('select * from films where genre sounds like "%' + [query] + '%"', function(err, genreResult) {
                    con.query('select * from films where category sounds like "%' + [query] + '%"', function(err, categoryResult) {
                        con.query('select * from films where description like "%' + [query] + '%"', function(err, descriptionResult) {
                            con.query('select * from films where summary like "%' + [query] + '%"', function(err, summaryResult) {
                                var result = {
                                    'title': titleResult,
                                    'genre': genreResult,
                                    'category': categoryResult,
                                    'description': descriptionResult,
                                    'summary': summaryResult
                                };
                                res.send(result);
                            })
                        })
                    })
                })
            })
        });
    };

    function getMatchingFilm(feature, films) {
        var result = films.filter(function(film) {
           return film.id == feature['film_id'];
        });
        return result[0];
    }

    this.getFeatured = function(res) {
        connection.acquire(function(err, con) {
            con.query('select * from featured', function(err, featuredResult) {
                con.query('select * from films', function(err, filmsResult) {
                    con.release();
                    var featured = [];
                    featuredResult.forEach(function(feature) {
                        var combo = {
                            "feature": feature,
                            "film": getMatchingFilm(feature, filmsResult)
                        };
                        featured.push(combo);
                    });
                    res.send(featured);
                });
            });
        });
    };

    this.specificFeature = function(id, res) {
        connection.acquire(function(err, con) {
            con.query('select * from featured where id = ?', [id], function(err, result) {
                con.query('select * from films where id = ?', result[0].film_id, function(err, filmsResult) {
                    con.release();
                    var single = {
                        "feature": result[0],
                        "film": filmsResult[0]
                    };
                    res.send(single);
                });
            });
        });
    };

    this.createFeatured = function(featured, res) {
        connection.acquire(function(err, con) {
            console.log(featured);
            con.query('insert into featured set ?', featured, function(err, result) {
                con.release();
                if (err) {
                    res.send({status: 1, message: 'Feature creation failed'});
                } else {
                    res.send({status: 0, message: 'Feature created successfully'});
                }
            });
        });
    };

    this.updateFeatured = function(featured, res) {
        connection.acquire(function(err, con) {
            con.query('update featured set ? where id = ?', [featured, featured.id], function(err, result) {
                con.release();
                if (err) {
                    res.send({status: 1, message: 'Feature update failed'});
                } else {
                    res.send({status: 0, message: 'Feature updated successfully'});
                }
            });
        });
    };

    this.deleteFeatured = function(id, res) {
        connection.acquire(function(err, con) {
            con.query('delete from featured where id = ?', [id], function(err, result) {
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