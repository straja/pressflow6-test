<div id="node-<?php print $node->nid; ?>" class="mainnews">
    <div class="title clear-block">
        <?php if(isset($title)): ?>
        <a href="<?php print $node_url ?>"><?php print $title; ?></a>
        <?php endif;?>
    </div>
    <?php if(isset($teaser_date)): ?>
    <div class="date clear-block"><?php print_r($teaser_date); ?></div>
    <?php endif;?>
    <?php if(isset($teaser_text)): ?>
        <div class="teaser-text clear-block"><?php print $teaser_text; ?></div>
        <a class="redlink" href="<?php print $node_url?>">Read more ></a>
    <?php endif;?>
</div>