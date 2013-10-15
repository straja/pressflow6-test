<div id="node-<?php print $node->nid; ?>" class="span-6 brand-image-teaser">
    <div class="title clear-block">
        <?php if(isset($title)): ?>
        <a href="<?php print $node_url ?>"><?php print $title; ?></a>
        <?php endif;?>
    </div>
    <div class="thumb clear-block"><a href="<?php print $node_url ?>"><?php print $thumb_image; ?></a></div>
    <?php if(isset($thumb_text)): ?>
        <div class="thumb-text clear-block"><?php print $thumb_text; ?></div>
        <a class="redlink" href="<?php print $node_url?>">Read more ></a>
    <?php endif;?>
</div>
