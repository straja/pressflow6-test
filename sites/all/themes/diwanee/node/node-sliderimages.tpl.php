<?php if(isset($slider_images)): ?>
<div id="slider">
    <div id="mask">
        <ul id="images">
            <?php for($i=0; $i<count($slider_images); $i++): ?>
                <li class="image"><?php print $slider_images[$i]; ?></li>
            <?php endfor; ?>
        </ul>
    </div>
</div>
<?php endif; ?>