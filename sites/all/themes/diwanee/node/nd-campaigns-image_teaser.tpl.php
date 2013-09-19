<div id="node-<?php print $node->nid; ?>" class="image-teaser clear-block">
    <?php if(isset($thumb_image)): ?>
    <a href="<?php print $node_url ?>"><?php print $thumb_image; ?></a>
    <?php endif;?>
    <div class="span-7 thumb-text">
        <?php if(isset($title)): ?>
        <a class="title" href="<?php print $node_url ?>"><?php print $title; ?></a>
        <?php endif;?>
        <?php if(isset($teaser_text)): ?>
          <div class="clear-block"><?php print $teaser_text; ?></div>
          <a class="redlink clear-block" href="<?php print $node_url?>">View campaign ></a>
        <?php endif;?>
    </div>
</div>
