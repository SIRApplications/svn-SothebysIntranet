<div class="<?php print $node_classes ?>" id="node-<?php print $node->nid; ?>">


  <?php if ($picture) print $picture; ?>


  <div class="content">
    <?php print $content; ?>
  </div>

  <?php if ($links): ?>
    <div class="links">
      <?php print $links; ?>
    </div>
  <?php endif; ?>

</div>
