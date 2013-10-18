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
    
    function jsUpdateSize(){
    // Get the dimensions of the viewport
        var width = window.innerWidth ||
                    document.documentElement.clientWidth ||
                    document.body.clientWidth;
        console.log(width);
        var menu = $('.pane-menu-block-1 ul.menu li');
        var sfHidden = $('.sf-hidden');
        if(width <= 640){
            sfHidden.remove();
            if(menu.length > 2) {
                //menu.append('<div id="brandPrev"><</div>')
                //menu.insertBefore('#brandPrev');
                menu.children().hide();
                menu.children().slice(0,2).show();
                if(!$('#brandNext').length){
                    $('.pane-menu-block-1 ul.menu').parent().append('<div id="brandNext">></div>');
                } else {
                    $('#brandNext').show();
                }
            }
        } else {
            if($('#brandNext').length){
                $('#brandNext').hide();
            }
            menu.children().show();
        }
    };
    window.onload = jsUpdateSize;       // When the page first loads
    window.onresize = jsUpdateSize;     // When the browser changes size
    
    $("#drandMenuArrow").click(function(){
        //TODO
    });
});