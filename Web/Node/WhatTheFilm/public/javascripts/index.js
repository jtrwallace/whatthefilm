$(document).ready( function() {

    $.ajax({
        type: "GET",
        url: '/films/',
        dataType: 'JSON',
        success: function(data) {
            console.log(data);
            $('#movie_title').text(data[0].title);
        }
    });

});