$(document).ready( function() {

    $('body').on('change', 'body', function(){
        alert('changed');
    });
    
    var isNew = 0;
    var isNewFeature = 0;
    
    $(document).on('click', '.title', function() {
        var id;
        if ($(this).data("id") == -1) {
            $.ajax({
                type: "GET",
                url: '/api/maxid/',
                success: function(data) {
                    $("#film_id > input").val(data.id + 1);
                    $("#film_title > input").val('');
                    $("#film_description > input").val("");
                    $("#film_summary > input").val("");
                    $("#film_genre > input").val("");
                    $("#film_duration > input").val("");
                    $("#film_category > input").val("");
                    $("#film_director > input").val("");
                    $("#film_actors > input").val("");
                    $("#film_year > input").val("");
                    $("#film_studio > input").val("");
                    $("#film_video > input").val("");
                    $("#film_poster > input").val("");
                    $("#film_still > input").val("");
                    $("#film_iphone_still > input").val("");
                    isNew = 1;
                }
            })
        } else {
            id = $(this).data("id");
            $.ajax({
                type: "GET",
                url: '/api/films/' + id,
                dataType: 'JSON',
                success: function(data) {
                    $("#film_id > input").val(data.id);
                    $("#film_title > input").val(data.title);
                    $("#film_description > input").val(data.description);
                    $("#film_summary > input").val(data.summary);
                    $("#film_genre > input").val(data.genre);
                    $("#film_duration > input").val(data.duration);
                    $("#film_category > input").val(data.category);
                    $("#film_director > input").val(data.director);
                    $("#film_actors > input").val(data.actors);
                    $("#film_year > input").val(data.year);
                    $("#film_studio > input").val(data.studio);
                    $("#film_video > input").val(data.video);
                    $("#film_poster > input").val(data.poster);
                    $("#film_still > input").val(data.still);
                    $("#film_iphone_still > input").val(data.iphonestill);
                    isNew = 0;
                }
            });
        }
        $("#button").show();
    });

    $(document).on('click', '.featured_title', function() {
        var id;
        if ($(this).data("id") == -1) {
            $.ajax({
                type: "GET",
                url: '/api/featured_maxid/',
                success: function(data) {
                    $("#featured_id > input").val(data.id + 1);
                    $("#featured_title > select").val('empty');
                    $("#featured_image > input").val("");
                    $("#featured_video > input").val("");
                    $("#featured_still > input").val("");
                    isNewFeature = 1;
                }
            })
        } else {
            id = $(this).data("id");
            $.ajax({
                type: "GET",
                url: '/api/featured/' + id,
                dataType: 'JSON',
                success: function(data) {
                    $("#featured_id > input").val(data['feature'].id);
                    $("#featured_title > select").val(data['film'].title);
                    $("#featured_image > input").val(data['feature'].image);
                    $("#featured_video > input").val(data['feature'].video);
                    $("#featured_still > input").val(data['feature'].videostill);
                    isNewFeature = 0;
                }
            });
        }
        $("#featured_button").show();
    });


    $("#button").click(function() {
        var film = {
            'id': $("#film_id > input").val(),
            'title': $("#film_title > input").val(),
            'description': $("#film_description > input").val(),
            'summary': $("#film_summary > input").val(),
            'genre': $("#film_genre > input").val(),
            'duration': $("#film_duration > input").val(),
            'category': $("#film_category > input").val(),
            'director': $("#film_director > input").val(),
            'actors': $("#film_actors > input").val(),
            'year': $("#film_year > input").val(),
            'studio': $("#film_studio > input").val(),
            'video': $("#film_video > input").val(),
            'poster': $("#film_poster > input").val(),
            'still': $("#film_still > input").val(),
            'iphonestill': $("#film_iphone_still > input").val()
        };
        if (isNew == 1) {
            $.ajax({
                type: "POST",
                url: '/api/films/',
                dataType: 'JSON',
                data: film,
                success: function() {
                    alert("Created!");
                    $("#list").append('<li data-id="' + film.id + '" class="title">' + film.title + '</li>');
                }
            })
        } else {
            $.ajax({
                type: "PUT",
                url: '/api/films/',
                dataType: 'JSON',
                data: film,
                success: function() {
                    alert("Saved!");
                }
            });
        }
    });

    $("#featured_button").click(function() {
        var feature = {
            'id': $("#featured_id > input").val(),
            'film_id': $("#featured_title > select").find(':selected').data('id'),
            'image': $("#featured_image > input").val(),
            'video': $("#featured_video > input").val(),
            'videostill': $("#featured_still > input").val()
        };
        console.log(feature);
        if (isNewFeature == 1) {
            $.ajax({
                type: "POST",
                url: '/api/featured/',
                dataType: 'JSON',
                data: feature,
                success: function() {
                    alert("Created!");
                    $("#featuredlist").append('<li data-id="' + feature.id + '" class="featured_title">' + $("#featured_title > select").val() + '</li>');
                }
            })
        } else {
            $.ajax({
                type: "PUT",
                url: '/api/featured/',
                dataType: 'JSON',
                data: feature,
                success: function() {
                    alert("Saved!");
                }
            });
        }
    });

});

