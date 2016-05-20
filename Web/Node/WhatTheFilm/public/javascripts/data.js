$(document).ready( function() {

    $('body').on('change', 'body', function(){
        alert('changed');
    });
    
    var isNew = 0;
    
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
                    isNew = 0;
                }
            });
        }
        $("#button").show();
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
            'still': $("#film_still > input").val()
        }
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

});

