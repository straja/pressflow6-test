/* 
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
$(document).ready(function() {
    $('.pane-menu-block-1 a').click(function(){
        if(!this.hasClass('active')){
            this.addClass('active');
        }
    });    

    $('#tabs li a:not(:first)').addClass('inactive');
    $('.tabContainer').hide();
    $('.tabContainer:first').show();

    $('#tabs li a').click(function(){
        var t = $(this).attr('id');
      if($(this).hasClass('inactive')){ //this is the start of our condition 
        $('#tabs li a').addClass('inactive');           
        $(this).removeClass('inactive');

        $('.tabContainer').hide();
        $('#'+ t + 'C').fadeIn('slow');
     }
    });
    
    $('#edit-submitted-message').focus(function(){
        $(this).text('');
    });
    $('#edit-submitted-name').focus(function(){
        $(this).text('');
        $(this).val('');
    });
    $('#edit-submitted-mail').focus(function(){
        $(this).text('');
        $(this).val('');
    });
    $('#edit-submitted-message').blur(function(){
        $(this).text('Message');
    });
    $('#edit-submitted-name').blur(function(){
        $(this).text('Name');
        $(this).val('Name');
    });
    $('#edit-submitted-mail').blur(function(){
        $(this).text('Mail');
        $(this).val('Mail');
    });
    
    // jsFiddle jquery slider
    var images = $('.view-slider.view-id-slider .views-row');
    var lastElem = images.length-1;
    var mask = $('.view-slider.view-id-slider .view-content');
    var imgWidth = images.find('img').width();
    var target = 0;

    $('.view-slider.view-id-slider .views-row:first-child').addClass('selected');
    mask.css('width', imgWidth*(lastElem+1) +'px');

    function sliderResponse(target) {
        mask.stop(true,false).animate({'left':'-'+ imgWidth*target +'px'},300);
        images.removeClass('selected');
        images.eq(target).addClass('selected');
    }
    
    $('.nextSlide').click(function() {
        var selected = $('.view-slider.view-id-slider .views-row.selected')
        target = $('.view-slider.view-id-slider .views-row').index(selected);
        target === lastElem ? target = 0 : target = target+1;
        sliderResponse(target);
        resetTiming();
    });
    $('.prevSlide').click(function() {
        var selected = $('.view-slider.view-id-slider .views-row.selected')
        target = $('.view-slider.view-id-slider .views-row').index(selected);
        lastElem = images.length-1;
        target === 0 ? target = lastElem : target = target-1;
        sliderResponse(target);
        resetTiming();
    });
    
    function sliderTiming() {
        var selected = $('.view-slider.view-id-slider .views-row.selected')
        target = $('.view-slider.view-id-slider .views-row').index(selected);
        target === lastElem ? target = 0 : target = target+1;
        sliderResponse(target);
    }
    var timingRun = setInterval(function() { sliderTiming(); },5000);
    function resetTiming() {
        clearInterval(timingRun);
        timingRun = setInterval(function() { sliderTiming(); },5000);
    }
    
});