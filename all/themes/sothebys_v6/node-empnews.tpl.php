<div class="news-block <?php print $node_classes ?>" id="node-<?php print $node->nid; ?>">
  <div class="news">
    <?php if ($picture) print $picture; ?>

    <?php if (count($taxonomy)): ?>
      <div class="taxonomy"><?php print t(' in ') . $terms ?></div>
    <?php endif; ?>

    <?php print $content; ?>

	<?php if ($links): ?>
	  <span class="newslinks">
	  <?php print $links; ?>
	  </span>
	<?php endif; ?>
  </div>
</div>