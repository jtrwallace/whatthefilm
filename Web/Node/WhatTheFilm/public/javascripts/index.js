$(document).ready( function() {

    $.ajax({
        type: "GET",
        url: '/api/films/',
        dataType: 'JSON',
        success: function(data) {
            $('#movie_title').text(data[0].description);
        }
    });

});