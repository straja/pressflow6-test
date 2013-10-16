$(document).ready(function() {
    var images = $('ul#images li.image');
    //var images = $('.view-slider.view-id-slider .views-row');
    var lastElem = images.length - 1;
    var mask = $('#mask');
    //var mask = $('.view-slider.view-id-slider .view-content');
    var imgWidth = images.width();
    var target = 0;
    
    if(images.length > 1) {
        mask.parent().append('<div id="arrows"><span class="control prevSlide"></span><span class="control nextSlide"></span></div>');
    }

    $('ul#images li.image:first-child').addClass('selected');
    mask.css('width', imgWidth*(lastElem+1) + 'px');

    function sliderResponse(target) {
        mask.stop(true,false).animate({'left':'-'+ imgWidth*target +'px'},300);
        images.removeClass('selected');
        images.eq(target).addClass('selected');
    }
    
    $('.nextSlide').click(function() {
        var selected = $('ul#images .selected')
        target = images.index(selected);
        target === lastElem ? target = 0 : target = target+1;
        sliderResponse(target);
        resetTiming();
    });
    $('.prevSlide').click(function() {
        var selected = $('ul#images .selected')
        target = images.index(selected);
        lastElem = images.length - 1;
        target === 0 ? target = lastElem : target = target-1;
        sliderResponse(target);
        resetTiming();
    });
    
    function sliderTiming() {
        var selected = $('ul#images .selected')
        target = images.index(selected);
        target === lastElem ? target = 0 : target = target+1;
        sliderResponse(target);
    }
    var timingRun = setInterval(function() { sliderTiming(); },5000);
    function resetTiming() {
        clearInterval(timingRun);
        timingRun = setInterval(function() { sliderTiming(); },5000);
    }
});