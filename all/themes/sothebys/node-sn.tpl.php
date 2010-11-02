<div class="news-block <?php print $node_classes ?>" id="node-<?php print $node->nid; ?>">
  <?php if ($page == 0): ?>
    <h4>
      <a href="<?php print $node_url; ?>"><?php print $title; ?></a>
    </h4>
  <?php else: ?>
    <h1>
      <?php print $title; ?>
    </h1>
  <?php endif; ?>
  <div class="news">
    <?php if ($picture) print $picture; ?>

    <?php //if ($submitted): ?>
      <?php //print $submitted ?>
    <?php //endif; ?>

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
