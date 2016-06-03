$(document).ready( function() {

    $('.featured-slider').unslider({
        autoplay: true,
        nav: false,
        arrows: false,
        speed: 1200,
        delay: 7500
    });

    $(document).find('.row').each(function () {

        if ($(this).find('.slidee').children().length < 5) {
            $(this).find('.scrollbar').hide();
        }

        var $frame  = $(this).find('.frame');
        var $slidee = $frame.children('ul').eq(0);
        var $wrap   = $frame.parent();

        // Call Sly on frame
        $frame.sly({
            horizontal: 1,
            itemNav: 'basic',
            smart: 1,
            activateOn: 'click',
            mouseDragging: 1,
            touchDragging: 1,
            releaseSwing: 1,
            startAt: 0,
            scrollBar: $wrap.find('.scrollbar'),
            scrollBy: 1,
            pagesBar: $wrap.find('.pages'),
            activatePageOn: 'click',
            speed: 300,
            elasticBounds: 1,
            easing: 'easeOutExpo',
            dragHandle: 1,
            dynamicHandle: 1,
            clickBar: 1
        });
    });
});