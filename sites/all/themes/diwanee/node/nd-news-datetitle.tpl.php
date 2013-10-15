<div id="node-<?php print $node->nid; ?>" class="datetitle clear-block">
    <div class="title">
    <?php if(isset($title)): ?>
    <a class="redlink" href="<?php print $node_url ?>"><?php print $title; ?></a>
    <?php endif;?>
    </div>
    <?php if(isset($teaser_date)): ?>
    <span class="date"><?php print_r($teaser_date); ?></span>
    <?php endif;?>
</div>
