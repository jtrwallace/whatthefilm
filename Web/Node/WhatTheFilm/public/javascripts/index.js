$(document).ready( function() {

    /*$.ajax({
        type: "GET",
        url: '/api/films/',
        dataType: 'JSON',
        success: function(data) {
            $('#movie_title').text(data[0].description);
        }
    });*/

    $('.featured-slider').unslider({
        autoplay: true,
        nav: false,
        arrows: false,
        speed: 1200,
        delay: 7500
    });

    $('#ca-container').contentcarousel();

});