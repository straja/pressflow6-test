<div id="node-<?php print $node->nid; ?>" class="offices">
    <div class="title clear-block">
        <?php if(isset($title)): ?>
           <b><?php print $title; ?></b>
        <?php endif;?>
    </div>
    <?php if(isset($body)): ?>
        <div class="body clear-block"><?php print $body; ?></div>
    <?php endif;?>
</div>