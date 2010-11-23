<div class="<?php print $node_classes ?>" id="node-<?php print $node->nid; ?>">
  <div id="homeImage">
    &nbsp;
  </div>
  <?php if ($picture) print $picture; ?>

  <?php if ($submitted): ?>
    <div class="submitted">
      <?php print $submitted ?>
    </div>
  <?php endif; ?>

  <?php if (count($taxonomy)): ?>
    <div class="taxonomy"><?php print t(' in ') . $terms ?></div>
  <?php endif; ?>

  <div class="content">
    <?php print $content; ?>
  </div>

  <?php if ($links): ?>
    <div class="links">
    Links:
      <?php print $links; ?>
    </div>
  <?php endif; ?>

</div>
