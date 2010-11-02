<!DOCTYPE html PUBliC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" lang="<?php print $language->language ?>" xml:lang="<?php print $language->language ?>">
<head>
<?php if ($user != ""): ?>
	<title><?php print $head_title; ?></title>
<?php endif; ?>
<?php if ($user == ""): ?>
	<title>Welcome to Sotheby's Intranet</title>
<?php endif; ?>

	<meta http-equiv="Content-Type" content="text/html; charset=iso-8859-1" />
  	<?php print $head; ?>
	<?php print $styles; ?>
	<?php print $scripts; ?>
	<link media="screen" type="text/css" rel="stylesheet" href="sothebys.css" />
</head>
<?php if ($user != ""): ?>
	<body id="userPage" class="<?php print $body_classes; ?>">
<?php endif; ?>
<?php if ($user == ""): ?>
	<body id="userPage" class="landing">
<?php endif; ?>
    <div class="container">
        <div id="quicklinks">
        	<?php if (!empty($quicklinks)): ?>
            	<?php print $quicklinks; ?>
            <?php endif; ?>
        </div>
        <div id="header">
            <h1>
            	<?php if (!empty($site_name)): ?>
	            	<a href="<?php print $front_page ?>" title="Sotheby's International Realty, Inc. Intranet Homepage" rel="home">
	              		<span class="alt"><?php print $site_name; ?></span>
	            	</a>
		        <?php endif; ?>
            	<!--  <a href="<?php print $front_page ?>"><span class="alt"><?php print $head_title ?></span></a> -->
            </h1>
			<div class="login">
				<?php if ($user != ""): ?><strong>Welcome, <?php print_r($user); ?>!</strong> <a href="/logout">Log Out</a><?php endif; ?>&nbsp;
	            <div id="headerLinks">
		        	<?php if (!empty($header_links)): ?>
		            	<?php print $header_links; ?>
		            <?php endif; ?>
		        </div>
		        <div class="quickSearch">
					<?php print $search_box; ?>
            	</div>
			</div>
        </div> <!-- End header -->
        
         <?php if (!empty($header_bottom)): ?>
        	<div id="headerBottom">
        		
        		<?php print $header_bottom; ?>
        	</div>
        <?php endif; ?>

        <div id="main">
			<?php if (!empty($left) && $user != ""): ?>
			    <div id="sideBar" class="loggedin">
					<?php print $left; ?>
			    </div> <!-- End sideBar -->
			<?php endif; ?>
            <div id="content">
					<?php if (!empty($mission)): ?>
			          <div id="mission"><?php print $mission; ?></div>
			        <?php endif; ?>
			        <?php if (!empty($content_top)):?>
			          <div id="content-top"><?php print $content_top; ?></div>
			        <?php endif; ?>
			        <div class="content">
			          <?php if (!empty($tabs)): ?>
			            <div class="tabs"><?php print $tabs; ?></div>
			          <?php endif; ?>
			          <?php print $help; ?>
			          <?php print $messages; ?>
			          <?php print $content; ?>
			          <?php if (!empty($feed_icons)): ?>
			            <div class="feed-icons"><?php print $feed_icons; ?></div>
			          <?php endif; ?>
			        </div> <!-- /content -->
			        <?php if (!empty($content_bottom)): ?>
			          <div id="content-bottom"><?php print $content_bottom; ?></div>
			        <?php endif; ?>
			      </div>
				<?php if (!empty($left) && $user == ""): ?>
				    <div id="sideBar">
						<?php print $left; ?>
				    </div> <!-- End sideBar -->
				<?php endif; ?>
			</div> <!-- End content -->
			<div id="footer" class="footer">
				<?php //if (!empty($footer)): ?>
	        		<?php print $footer; ?>
	        	<?php //endif; ?>
			</div> <!-- End footer -->
        </div> <!-- End main -->
     </div> <!-- End container -->
     <?php print $closure ?>
</body>
</html>
