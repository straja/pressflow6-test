<div id="node-<?php print $node->nid; ?>" class="full_node">
    <ul id="tabs">

          <li><a id="tab1">Overview</a></li>
          <?php if(isset($mediakit)): ?>
            <li><a id="tab2">Media kit</a></li>
          <?php endif;?>

    </ul>
    <div class="tabContainer" id="tab1C">
        <?php if(isset($body)): ?>
            <div class="body clear-block"><?php print $body; ?></div>
        <?php endif; ?>
        <?php if(isset($images)): ?>
            <div class="clear-block">
                <?php foreach ($images as $image): ?>
                    <div class="image"><?php print $image; ?></div>
                <?php endforeach; ?>
            </div>
        <?php endif; ?>
        <?php if(isset($summary)): ?>
            <div class="summary clear-block"><?php print $summary; ?></div>
        <?php endif; ?>
        <div class="clear-block">Visit website: <a class="redlink" href="<?php print $website['url']; ?>"><?php print $website['title']; ?></a></div>
    </div>
    <?php if(isset($mediakit)):?>
        <div class="tabContainer" id="tab2C">
            <?php print $mediakit; ?>
        </div>
    <?php endif; ?>
</div>