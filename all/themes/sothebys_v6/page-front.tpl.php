<!DOCTYPE html PUBliC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
	lang="<?php print $language->language ?>"
	xml:lang="<?php print $language->language ?>">
<head>
<title><?php print $head_title; ?></title>
<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
<?php print $head; ?>
<?php print $styles; ?>
<?php print $scripts; ?>
<link media="screen" type="text/css" rel="stylesheet"
	href="sothebys.css" />
</head>
<body class="<?php print $body_class; ?>">
<div class="container">
<div id="header">
<h1><?php if (!empty($site_name)): ?> <a
	href="<?php print $front_page ?>"
	title="Sotheby's International Realty, Inc. Intranet Homepage"
	rel="home"> <span class="alt"><?php print $site_name; ?></span> </a> <?php endif; ?>
<!--  <a href="<?php print $front_page ?>"><span class="alt"><?php print $head_title ?></span></a> -->
</h1>

<div class="login">
<?php  global $user; ?>
<?php if ($user->uid) : ?>
	<div id="loginInfo">
		<strong>Welcome,  <?php print l($user->name,'user/'.$user->uid); ?></strong>
		<?php print l(" Log Out","logout"); ?>
	</div>
<?php endif; ?>&nbsp;

<div id="headerLinks"><?php if (!empty($header_links)): ?> <?php print $header_links; ?>
<?php endif; ?></div>
<div class="quickSearch"><?php print $search_box; ?></div>
</div>

<!--<div class="nav"></div>--></div>
<?php print $bob; ?>
<!-- End header --> <?php if (!empty($header_bottom)): ?>
<div id="headerBottom" class="<?php print menu_get_active_trail_stuff(); ?>"><?php print $header_bottom; ?></div>
<?php endif; ?>
<div id="main">
<div id="content">
<div id="tabBar"></div>
<?php if (!empty($breadcrumb)): ?>
<div class="breadcrumbs"><?php print $breadcrumb; ?></div>
<?php endif; ?> <?php if (!empty($mission)): ?>
<div id="mission"><?php print $mission; ?></div>
<?php endif; ?> <?php if (!empty($content_top)):?>
<div id="content-top"><?php print $content_top; ?></div>
<?php endif; ?>
<div class="content"><?php if (!empty($tabs)): ?>
<div class="tabs"><?php print $tabs; ?></div>
<?php endif; ?> <?php print $help; ?> <?php print $messages; ?> <?php print $content; ?>
<?php if (!empty($feed_icons)): ?>
<div class="feed-icons"><?php print $feed_icons; ?></div>
<?php endif; ?></div>
<!-- /content --> <?php if (!empty($content_bottom)): ?>
<div id="content-bottom"><?php print $content_bottom; ?></div>
<?php endif; ?></div>
</div>
<!-- End content --></div>
<!-- End main -->
<div id="footer" class="footer"><?php print $footer; ?></div>
<!-- End footer -->
</div>
<!-- End container -->
<?php print $closure ?>

<script type="text/javascript">
var gaJsHost = (("https:" == document.location.protocol) ? 
"https://ssl." : "http://www.");
document.write(unescape("%3Cscript src='" + gaJsHost + 
"google-analytics.com/ga.js' type='text/javascript'%3E%3C/script%3E"));
</script>
<script type="text/javascript">
try {
var pageTracker = _gat._getTracker("UA-2975071-10");
pageTracker._trackPageview();
} catch(err) {}</script>

</body>
</html>
