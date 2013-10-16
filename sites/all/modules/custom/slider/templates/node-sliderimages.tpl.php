<?php if(isset($node)): ?>
<div id="slider">
    <div id="mask">
        <ul id="images">
            <?php for($i=0; $i<count($node->field_image); $i++): ?>
            <li class="image"><img src="<?php print base_path() . $node->field_image[$i]['filepath']; ?>" /></li>
            <?php endfor; ?>
        </ul>
        </div>
    </div>
</div>
<?php endif; ?>