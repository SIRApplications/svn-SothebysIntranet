<div class="<?php print $node_classes ?>"
	id="node-<?php print $node->nid; ?>"><?php if (count($taxonomy)): ?>
<div class="headerImage <?php print strip_tags($terms); ?>"></div>
<?php endif; ?>

<?php if ($picture) print $picture; ?> 

<div class="content"><?php print $content; ?></div>

<?php if ($links): ?>
<div class="links"><?php print $links; ?></div>
<?php endif; ?></div>
