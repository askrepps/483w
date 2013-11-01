<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>CCMenuItemSlider.cpp | Cocos2d-x</title>
<meta name="description" content="cocos2d-x is a cross platform open source free 2D game engine for mobile gamedev, that is fast and stable, easy to learn and use" />
<meta name="keywords" content="cocos2d-x,cocos2d,game engine,opengl,cross,multi,platform,iphone,ipad,android,windows,metro,bada,marmalade,playbook" />
<meta name="csrf-param" content="authenticity_token"/>
<meta name="csrf-token" content="IoScIQLqLoTrq0UGcW8p3EYcZiQ9CfHVkQIswQwL6Jc="/>
<script type="text/javascript">
//<![CDATA[
window.__CF=window.__CF||{};window.__CF.AJS={"ga_key":{"ua":"UA-3216502-3","ga_bs":"2"},"vig_key":{"sid":"d654e26afef9085d79aba37dfe97be28"}};
//]]>
</script>
<script type="text/javascript">
//<![CDATA[
try{if (!window.CloudFlare) { var CloudFlare=[{verbose:0,p:0,byc:0,owlid:"cf",bag2:1,mirage2:0,oracle:0,paths:{cloudflare:"/cdn-cgi/nexp/abv=2980380653/"},atok:"d7d12ab6e47ebd18df436caeb22a79f2",petok:"6de43737d9ecce3eaba2b43b5c21e831-1383269804-1800",zone:"cocos2d-x.org",rocket:"0",apps:{"ga_key":{"ua":"UA-3216502-3","ga_bs":"2"},"vig_key":{"sid":"d654e26afef9085d79aba37dfe97be28"}}}];var a=document.createElement("script"),b=document.getElementsByTagName("script")[0];a.async=!0;a.src="//ajax.cloudflare.com/cdn-cgi/nexp/abv=616370820/cloudflare.min.js";b.parentNode.insertBefore(a,b);}}catch(e){};
//]]>
</script>
<link rel='shortcut icon' href='http://files.cocos2d-x.org/favicon.ico?1379002932' />
<link href="http://files.cocos2d-x.org/stylesheets/application.css?1381394682" media="all" rel="stylesheet" type="text/css" />

<link href="http://files.cocos2d-x.org/stylesheets/coderay.css?1379003079" media="all" rel="stylesheet" type="text/css" />
<link href="http://files.cocos2d-x.org/stylesheets/style.css?1382080396" media="all" rel="stylesheet" type="text/css" />

<script type="text/javascript" src="http://w.sharethis.com/button/buttons.js"></script>
<script type="text/javascript">stLight.options({publisher: "d7067c60-ba30-40ba-a7db-6db0699b48d6"}); </script>

<script src="http://files.cocos2d-x.org/javascripts/jquery-1.8.2.min.js?1379003123" type="text/javascript"></script>
<script src="http://files.cocos2d-x.org/javascripts/jquery.easing.1.3.js?1379003123" type="text/javascript"></script>
<script src="http://files.cocos2d-x.org/javascripts/jquery.timeago.js?1379003123" type="text/javascript"></script>
<script type="text/javascript">
var jQuery=$;
</script>

<script src="http://files.cocos2d-x.org/javascripts/prototype.js?1379002926" type="text/javascript"></script>
<script src="http://files.cocos2d-x.org/javascripts/effects.js?1379002926" type="text/javascript"></script>
<script src="http://files.cocos2d-x.org/javascripts/dragdrop.js?1379002926" type="text/javascript"></script>
<script src="http://files.cocos2d-x.org/javascripts/controls.js?1379002926" type="text/javascript"></script>
<script src="http://files.cocos2d-x.org/javascripts/application.js?1379002926" type="text/javascript"></script>
<script type="text/javascript">
//<![CDATA[
Event.observe(window, 'load', function(){ new WarnLeavingUnsaved('The current page contains unsaved text that will be lost if you leave this page.'); });
//]]>
</script>
<!--[if IE 6]>
    <style type="text/css">
      * html body{ width: expression( document.documentElement.clientWidth < 960 ? '960px' : '100%' ); }
      body {behavior: url(http://files.cocos2d-x.org/stylesheets/csshover.htc?1379002929);}
    </style>
<![endif]-->
<link href="http://files.cocos2d-x.org/plugin_assets/redmine_ads/stylesheets/redmine_ads.css?1379002926" media="screen" rel="stylesheet" type="text/css" /> <style type="text/css">#admin-menu a.contacts { background-image: url('http://files.cocos2d-x.org/plugin_assets/redmine_contacts/images/vcard.png?1379002926'); }</style> 


<!-- page specific tags -->
    <link href="http://files.cocos2d-x.org/stylesheets/scm.css?1379003079" media="screen" rel="stylesheet" type="text/css" /><script type="text/javascript">
/* <![CDATA[ */
var _gaq = _gaq || [];
_gaq.push(['_setAccount', 'UA-3216502-3']);
_gaq.push(['_trackPageview']);

(function() {
var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
ga.src = ('https:' == document.location.protocol ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
})();

(function(b){(function(a){"__CF"in b&&"DJS"in b.__CF?b.__CF.DJS.push(a):"addEventListener"in b?b.addEventListener("load",a,!1):b.attachEvent("onload",a)})(function(){"FB"in b&&"Event"in FB&&"subscribe"in FB.Event&&(FB.Event.subscribe("edge.create",function(a){_gaq.push(["_trackSocial","facebook","like",a])}),FB.Event.subscribe("edge.remove",function(a){_gaq.push(["_trackSocial","facebook","unlike",a])}),FB.Event.subscribe("message.send",function(a){_gaq.push(["_trackSocial","facebook","send",a])}));"twttr"in b&&"events"in twttr&&"bind"in twttr.events&&twttr.events.bind("tweet",function(a){if(a){var b;if(a.target&&a.target.nodeName=="IFRAME")a:{if(a=a.target.src){a=a.split("#")[0].match(/[^?=&]+=([^&]*)?/g);b=0;for(var c;c=a[b];++b)if(c.indexOf("url")===0){b=unescape(c.split("=")[1]);break a}}b=void 0}_gaq.push(["_trackSocial","twitter","tweet",b])}})})})(window);
/* ]]> */
</script>
</head>
<body class="controller-attachments action-show main-body">

  <div id="head">
  <div class="w960">
    <div class="logo"><a href="/"></a></div>
    <div class="nav-box">
      <ul class="navbar">
        <li class=nil ><a href="/features">Features</a></li>
        <li class=nil><a href="/news">News</a></li>
        <li class=nil><a href="/forums">Community</a></li>
        <li class=nil><a href="/games">Games</a></li>
        <li class=nil><a href="/download">Download</a></li>
        <li class=nil><a href="/wiki">Learn</a></li>
        <li class=nil><a href="/hub">Hub</a></li>
      </ul>
      <div class="top-menu">
        <div class="project-box">
          <a href="/projects" class="projects">PROJECTS</a>
          <div class="project-list"><s></s>
            <ul><li><a href="/projects/cocos2d-x">cocos2d-x</a></li><li><a href="/projects/document">&nbsp;&nbsp;&#187; document</a></li><li><a href="/projects/html5">&nbsp;&nbsp;&#187; html5</a></li><li><a href="/projects/native">&nbsp;&nbsp;&#187; native</a></li><li><a href="/projects/studio">&nbsp;&nbsp;&#187; studio</a></li><li><a href="/projects/website">&nbsp;&nbsp;&#187; website</a></li></ul>
          </div>
        </div>
        
        
          <a href="/account/register" class="signup">SIGN UP</a>
          <div class="login-box"><a class="login-a">LOG IN</a><s></s>
            <div class="login-detail">
              <form action="/login" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="IoScIQLqLoTrq0UGcW8p3EYcZiQ9CfHVkQIswQwL6Jc=" /></div>
                <ul>
                  <li>
                    <input id="username" name="username" placeholder="Login" type="text" />
                  </li>
                  <li>
                    <input id="password" name="password" placeholder="Password" type="password" />
                  </li>
                  
                    <label for="autologin"><input id="autologin" name="autologin" type="checkbox" value="1" /> Stay logged in</label>
                  
                  <li>
                    <input type="submit" class="login-btn" value="" />
                    <em>Password <a href="/account/lost_password">Forgot?</a></em></li>
                </ul>
              </form>
            </div>
          </div>
        
      </div>
    </div>
  </div>
</div>

<script type="text/javascript">
jQuery(document).ready(function(){
jQuery('.login-a').toggle(
  function(){
    jQuery(this).addClass('on');
    jQuery('.login-detail,.login-box s').stop().show()
  },
  function(){
    jQuery(this).removeClass('on');
    jQuery('.login-detail,.login-box s').stop().hide();
  });

jQuery('.member-box').hover(
  function(){
    jQuery(this).children('a').addClass('on');
    jQuery('.login-detail,.login-detail s').stop().show()},
  function(){
    jQuery(this).children('a').removeClass('on');
    jQuery('.login-detail,.login-box s').stop().hide();
  });

jQuery('.project-box').hover(
  function(){
    jQuery(this).children('a').addClass('on');
    jQuery('.project-list, .project-list s').stop().show()},
  function(){
    jQuery(this).children('a').removeClass('on');
    jQuery('.project-list, .project-list s').stop().hide();
  });
});
</script>

  <div class="channel-nav">
  <div class="w960">
    <div id="quick-search" class="channel-search">
      <form action="/search" method="get">
      
      <input accesskey="f" class="text" id="q" name="q" size="20" type="text" />
      <input name="commit" type="submit" value="" />
      </form>
    </div>
    
  </div>
</div>

<div class="w960">
  
</div>


  <div class="content-body">
  
    
      <div id="content" class="w960">
        
        <h2>CCMenuItemSlider.cpp</h2>

<div class="attachments">
<p>
   <span class="author"><a href="/users/399" class="blue">Songyuan Zhao</a>, 2011-12-13 05:28</span></p>
<p><a href="/attachments/download/669/CCMenuItemSlider.cpp">Download</a>   <span class="size">(6.8 kB)</span></p>

</div>
&nbsp;
<div class="autoscroll">
<table class="filecontent syntaxhl">
<tbody>


  <tr>
    <th class="line-num" id="L1">
      <a href="#L1">1</a>
    </th>
    <td class="line-code">
      <pre><span class="preprocessor">#include</span> <span class="include">&quot;CCMenuItemSlider.h&quot;</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L2">
      <a href="#L2">2</a>
    </th>
    <td class="line-code">
      <pre><span class="preprocessor">#include</span> <span class="include">&quot;CCPointExtension.h&quot;</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L3">
      <a href="#L3">3</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L4">
      <a href="#L4">4</a>
    </th>
    <td class="line-code">
      <pre>CCMenuItemSlider* CCMenuItemSlider::itemFromNormalSprite(<span class="local-variable">CCNode</span>* trackSprite, <span class="local-variable">CCNode</span>* knobSprite)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L5">
      <a href="#L5">5</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L6">
      <a href="#L6">6</a>
    </th>
    <td class="line-code">
      <pre>   <span class="keyword">return</span> CCMenuItemSlider::itemFromNormalSprite(trackSprite, knobSprite, <span class="predefined-constant">NULL</span>, <span class="predefined-constant">NULL</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L7">
      <a href="#L7">7</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L8">
      <a href="#L8">8</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L9">
      <a href="#L9">9</a>
    </th>
    <td class="line-code">
      <pre>CCMenuItemSlider* CCMenuItemSlider::itemFromNormalSprite(<span class="local-variable">CCNode</span>* trackSprite, <span class="local-variable">CCNode</span>* knobSprite, SelectorProtocol* target, SEL_MenuHandler selector)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L10">
      <a href="#L10">10</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L11">
      <a href="#L11">11</a>
    </th>
    <td class="line-code">
      <pre>        CCMenuItemSlider *pRet = <span class="keyword">new</span> CCMenuItemSlider();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L12">
      <a href="#L12">12</a>
    </th>
    <td class="line-code">
      <pre>        pRet-&gt;initFromNormalSprite(trackSprite, knobSprite, target, selector); 
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L13">
      <a href="#L13">13</a>
    </th>
    <td class="line-code">
      <pre>        pRet-&gt;autorelease();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L14">
      <a href="#L14">14</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">return</span> pRet;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L15">
      <a href="#L15">15</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L16">
      <a href="#L16">16</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L17">
      <a href="#L17">17</a>
    </th>
    <td class="line-code">
      <pre><span class="predefined-type">bool</span> CCMenuItemSlider::initFromNormalSprite(<span class="local-variable">CCNode</span>* trackSprite, <span class="local-variable">CCNode</span>* knobSprite, SelectorProtocol* target, SEL_MenuHandler selector)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L18">
      <a href="#L18">18</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L19">
      <a href="#L19">19</a>
    </th>
    <td class="line-code">
      <pre>        assert(trackSprite != <span class="predefined-constant">NULL</span> &amp;&amp; knobSprite != <span class="predefined-constant">NULL</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L20">
      <a href="#L20">20</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L21">
      <a href="#L21">21</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span>( <span class="local-variable">CCMenuItem</span>::initWithTarget(target, selector) ) 
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L22">
      <a href="#L22">22</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L23">
      <a href="#L23">23</a>
    </th>
    <td class="line-code">
      <pre>                m_trackImage    = trackSprite;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L24">
      <a href="#L24">24</a>
    </th>
    <td class="line-code">
      <pre>                m_knobImage                = knobSprite;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L25">
      <a href="#L25">25</a>
    </th>
    <td class="line-code">
      <pre>        
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L26">
      <a href="#L26">26</a>
    </th>
    <td class="line-code">
      <pre>                m_trackImage-&gt;setAnchorPoint(<span class="local-variable">ccp</span>(<span class="integer">0</span>, <span class="integer">0</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L27">
      <a href="#L27">27</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L28">
      <a href="#L28">28</a>
    </th>
    <td class="line-code">
      <pre>                m_isVertical = (m_trackImage-&gt;getContentSize().height &gt; m_trackImage-&gt;getContentSize().width);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L29">
      <a href="#L29">29</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L30">
      <a href="#L30">30</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">if</span> (m_isVertical)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L31">
      <a href="#L31">31</a>
    </th>
    <td class="line-code">
      <pre>                {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L32">
      <a href="#L32">32</a>
    </th>
    <td class="line-code">
      <pre>                        <span class="predefined-type">float</span> offset = (m_knobImage-&gt;getContentSize().width - m_trackImage-&gt;getContentSize().width)/<span class="integer">2</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L33">
      <a href="#L33">33</a>
    </th>
    <td class="line-code">
      <pre>                        m_trackImage-&gt;setPosition(<span class="local-variable">ccp</span>(offset, <span class="integer">0</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L34">
      <a href="#L34">34</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L35">
      <a href="#L35">35</a>
    </th>
    <td class="line-code">
      <pre>                        setContentSize(<span class="local-variable">CCSizeMake</span>(m_knobImage-&gt;getContentSize().width, m_trackImage-&gt;getContentSize().height));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L36">
      <a href="#L36">36</a>
    </th>
    <td class="line-code">
      <pre>                }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L37">
      <a href="#L37">37</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">else</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L38">
      <a href="#L38">38</a>
    </th>
    <td class="line-code">
      <pre>                {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L39">
      <a href="#L39">39</a>
    </th>
    <td class="line-code">
      <pre>                        <span class="predefined-type">float</span> offset = (m_knobImage-&gt;getContentSize().height - m_trackImage-&gt;getContentSize().height)/<span class="integer">2</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L40">
      <a href="#L40">40</a>
    </th>
    <td class="line-code">
      <pre>                        m_trackImage-&gt;setPosition(<span class="local-variable">ccp</span>(<span class="integer">0</span>, offset));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L41">
      <a href="#L41">41</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L42">
      <a href="#L42">42</a>
    </th>
    <td class="line-code">
      <pre>                        setContentSize(<span class="local-variable">CCSizeMake</span>(m_trackImage-&gt;getContentSize().width, m_knobImage-&gt;getContentSize().height));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L43">
      <a href="#L43">43</a>
    </th>
    <td class="line-code">
      <pre>                }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L44">
      <a href="#L44">44</a>
    </th>
    <td class="line-code">
      <pre>                
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L45">
      <a href="#L45">45</a>
    </th>
    <td class="line-code">
      <pre>                addChild(trackSprite, <span class="integer">1</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L46">
      <a href="#L46">46</a>
    </th>
    <td class="line-code">
      <pre>                addChild(knobSprite, <span class="integer">2</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L47">
      <a href="#L47">47</a>
    </th>
    <td class="line-code">
      <pre>                
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L48">
      <a href="#L48">48</a>
    </th>
    <td class="line-code">
      <pre>                m_minValue        = <span class="float">0</span><span class="float">.0f</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L49">
      <a href="#L49">49</a>
    </th>
    <td class="line-code">
      <pre>                m_maxValue        = <span class="integer">10</span><span class="float">0</span><span class="float">.0f</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L50">
      <a href="#L50">50</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L51">
      <a href="#L51">51</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 char temp_char[16];</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L52">
      <a href="#L52">52</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 sprintf(temp_char, &quot;%.1f&quot;, m_minValue);</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L53">
      <a href="#L53">53</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 CCLabelTTF* labelMin = CCLabelTTF::labelWithString(temp_char, &quot;Arial&quot;, 10);</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L54">
      <a href="#L54">54</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 labelMin-&gt;setPosition(ccp(0, 0));</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L55">
      <a href="#L55">55</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//         addChild(labelMin, 3);</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L56">
      <a href="#L56">56</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//        </span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L57">
      <a href="#L57">57</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 sprintf(temp_char, &quot;%.1f&quot;, m_maxValue);</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L58">
      <a href="#L58">58</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 CCLabelTTF* labelMax = CCLabelTTF::labelWithString(temp_char, &quot;Arial&quot;, 10);</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L59">
      <a href="#L59">59</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 labelMax-&gt;setPosition(ccp(m_trackImage-&gt;getContentSize().width, 0));</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L60">
      <a href="#L60">60</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//                 addChild(labelMax);</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L61">
      <a href="#L61">61</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L62">
      <a href="#L62">62</a>
    </th>
    <td class="line-code">
      <pre>                <span class="comment">//remove it if you like</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L63">
      <a href="#L63">63</a>
    </th>
    <td class="line-code">
      <pre>                m_labelValue = <span class="local-variable">CCLabelTTF</span>::labelWithString(<span class="string"><span class="delimiter">&quot;</span><span class="delimiter">&quot;</span></span>, <span class="string"><span class="delimiter">&quot;</span><span class="content">Arial</span><span class="delimiter">&quot;</span></span>, <span class="integer">10</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L64">
      <a href="#L64">64</a>
    </th>
    <td class="line-code">
      <pre>                m_labelValue-&gt;setPosition(<span class="local-variable">ccp</span>(m_trackImage-&gt;getContentSize().width/<span class="integer">2</span>, <span class="integer">0</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L65">
      <a href="#L65">65</a>
    </th>
    <td class="line-code">
      <pre>                addChild(m_labelValue, <span class="integer">3</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L66">
      <a href="#L66">66</a>
    </th>
    <td class="line-code">
      <pre>                <span class="comment">//</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L67">
      <a href="#L67">67</a>
    </th>
    <td class="line-code">
      <pre>                setValue(<span class="integer">5</span><span class="float">0</span><span class="float">.0f</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L68">
      <a href="#L68">68</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L69">
      <a href="#L69">69</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L70">
      <a href="#L70">70</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">return</span> <span class="predefined-constant">true</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L71">
      <a href="#L71">71</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L72">
      <a href="#L72">72</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L73">
      <a href="#L73">73</a>
    </th>
    <td class="line-code">
      <pre><span class="directive">void</span> CCMenuItemSlider::setValue(<span class="predefined-type">float</span> aValue)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L74">
      <a href="#L74">74</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L75">
      <a href="#L75">75</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span>        valueRatio;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L76">
      <a href="#L76">76</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L77">
      <a href="#L77">77</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (m_isVertical)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L78">
      <a href="#L78">78</a>
    </th>
    <td class="line-code">
      <pre>                valueRatio        = (m_trackImage-&gt;getContentSize().height - m_knobImage-&gt;getContentSize().height) / (m_maxValue - m_minValue);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L79">
      <a href="#L79">79</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">else</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L80">
      <a href="#L80">80</a>
    </th>
    <td class="line-code">
      <pre>                valueRatio        = (getContentSize().width - m_knobImage-&gt;getContentSize().width) / (m_maxValue - m_minValue);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L81">
      <a href="#L81">81</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L82">
      <a href="#L82">82</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (aValue &lt; m_minValue)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L83">
      <a href="#L83">83</a>
    </th>
    <td class="line-code">
      <pre>                m_value        = m_minValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L84">
      <a href="#L84">84</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">else</span> <span class="keyword">if</span> (aValue &gt; m_maxValue)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L85">
      <a href="#L85">85</a>
    </th>
    <td class="line-code">
      <pre>                m_value        = m_maxValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L86">
      <a href="#L86">86</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">else</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L87">
      <a href="#L87">87</a>
    </th>
    <td class="line-code">
      <pre>                m_value        = aValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L88">
      <a href="#L88">88</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L89">
      <a href="#L89">89</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (m_isVertical)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L90">
      <a href="#L90">90</a>
    </th>
    <td class="line-code">
      <pre>                m_knobImage-&gt;setPosition(<span class="local-variable">ccp</span>(getContentSize().width / <span class="integer">2</span>,
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L91">
      <a href="#L91">91</a>
    </th>
    <td class="line-code">
      <pre>                (m_value - m_minValue) * valueRatio + m_knobImage-&gt;getContentSize().height / <span class="integer">2</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L92">
      <a href="#L92">92</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">else</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L93">
      <a href="#L93">93</a>
    </th>
    <td class="line-code">
      <pre>                m_knobImage-&gt;setPosition(<span class="local-variable">ccp</span>((m_value - m_minValue) * valueRatio + m_knobImage-&gt;getContentSize().width / <span class="integer">2</span>,
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L94">
      <a href="#L94">94</a>
    </th>
    <td class="line-code">
      <pre>                getContentSize().height / <span class="integer">2</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L95">
      <a href="#L95">95</a>
    </th>
    <td class="line-code">
      <pre>    
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L96">
      <a href="#L96">96</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L97">
      <a href="#L97">97</a>
    </th>
    <td class="line-code">
      <pre>        <span class="comment">//remove it if you like</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L98">
      <a href="#L98">98</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">char</span> temp_char[<span class="integer">16</span>];
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L99">
      <a href="#L99">99</a>
    </th>
    <td class="line-code">
      <pre>        sprintf(temp_char, <span class="string"><span class="delimiter">&quot;</span><span class="content">%.1f</span><span class="delimiter">&quot;</span></span>, m_value);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L100">
      <a href="#L100">100</a>
    </th>
    <td class="line-code">
      <pre>        m_labelValue-&gt;setString(temp_char);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L101">
      <a href="#L101">101</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L102">
      <a href="#L102">102</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L103">
      <a href="#L103">103</a>
    </th>
    <td class="line-code">
      <pre><span class="directive">void</span> CCMenuItemSlider::setColor(<span class="directive">const</span> ccColor3B&amp; color)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L104">
      <a href="#L104">104</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L105">
      <a href="#L105">105</a>
    </th>
    <td class="line-code">
      <pre>        m_trackImage-&gt;convertToRGBAProtocol()-&gt;setColor(color);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L106">
      <a href="#L106">106</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L107">
      <a href="#L107">107</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L108">
      <a href="#L108">108</a>
    </th>
    <td class="line-code">
      <pre><span class="directive">const</span> ccColor3B&amp; CCMenuItemSlider::getColor(<span class="directive">void</span>)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L109">
      <a href="#L109">109</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L110">
      <a href="#L110">110</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">return</span> m_trackImage-&gt;convertToRGBAProtocol()-&gt;getColor();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L111">
      <a href="#L111">111</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L112">
      <a href="#L112">112</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L113">
      <a href="#L113">113</a>
    </th>
    <td class="line-code">
      <pre>GLubyte CCMenuItemSlider::getOpacity(<span class="directive">void</span>)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L114">
      <a href="#L114">114</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L115">
      <a href="#L115">115</a>
    </th>
    <td class="line-code">
      <pre>   <span class="keyword">return</span> m_trackImage-&gt;convertToRGBAProtocol()-&gt;getOpacity();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L116">
      <a href="#L116">116</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L117">
      <a href="#L117">117</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L118">
      <a href="#L118">118</a>
    </th>
    <td class="line-code">
      <pre><span class="directive">void</span> CCMenuItemSlider::setOpacity(GLubyte opacity)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L119">
      <a href="#L119">119</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L120">
      <a href="#L120">120</a>
    </th>
    <td class="line-code">
      <pre>        m_trackImage-&gt;convertToRGBAProtocol()-&gt;setOpacity(opacity);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L121">
      <a href="#L121">121</a>
    </th>
    <td class="line-code">
      <pre>        m_knobImage-&gt;convertToRGBAProtocol()-&gt;setOpacity(opacity);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L122">
      <a href="#L122">122</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L123">
      <a href="#L123">123</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L124">
      <a href="#L124">124</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L125">
      <a href="#L125">125</a>
    </th>
    <td class="line-code">
      <pre><span class="directive">void</span> CCMenuItemSlider::dragToPoint(<span class="local-variable">CCPoint</span> aPoint)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L126">
      <a href="#L126">126</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L127">
      <a href="#L127">127</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span>        valueRatio;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L128">
      <a href="#L128">128</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span>        absValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L129">
      <a href="#L129">129</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L130">
      <a href="#L130">130</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (m_isVertical) {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L131">
      <a href="#L131">131</a>
    </th>
    <td class="line-code">
      <pre>                valueRatio        = (m_maxValue - m_minValue) / (getContentSize().height - m_knobImage-&gt;getContentSize().height);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L132">
      <a href="#L132">132</a>
    </th>
    <td class="line-code">
      <pre>                absValue        = aPoint.y - m_knobImage-&gt;getContentSize().height / <span class="integer">2</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L133">
      <a href="#L133">133</a>
    </th>
    <td class="line-code">
      <pre>        } <span class="keyword">else</span> {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L134">
      <a href="#L134">134</a>
    </th>
    <td class="line-code">
      <pre>                valueRatio        = (m_maxValue - m_minValue) / (getContentSize().width - m_knobImage-&gt;getContentSize().width);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L135">
      <a href="#L135">135</a>
    </th>
    <td class="line-code">
      <pre>                absValue        = aPoint.x - m_knobImage-&gt;getContentSize().width / <span class="integer">2</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L136">
      <a href="#L136">136</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L137">
      <a href="#L137">137</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L138">
      <a href="#L138">138</a>
    </th>
    <td class="line-code">
      <pre>        setValue(m_minValue + absValue * valueRatio);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L139">
      <a href="#L139">139</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L140">
      <a href="#L140">140</a>
    </th>
    <td class="line-code">
      <pre>        activate();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L141">
      <a href="#L141">141</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L142">
      <a href="#L142">142</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L143">
      <a href="#L143">143</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L144">
      <a href="#L144">144</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L145">
      <a href="#L145">145</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L146">
      <a href="#L146">146</a>
    </th>
    <td class="line-code">
      <pre><span class="comment">//Menu</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L147">
      <a href="#L147">147</a>
    </th>
    <td class="line-code">
      <pre>CCMenuSlider* CCMenuSlider::menuWithItems(CCMenuItemSlider* item, ...)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L148">
      <a href="#L148">148</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L149">
      <a href="#L149">149</a>
    </th>
    <td class="line-code">
      <pre>        va_list args;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L150">
      <a href="#L150">150</a>
    </th>
    <td class="line-code">
      <pre>        va_start(args,item);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L151">
      <a href="#L151">151</a>
    </th>
    <td class="line-code">
      <pre>        CCMenuSlider *pRet = <span class="keyword">new</span> CCMenuSlider();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L152">
      <a href="#L152">152</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (pRet &amp;&amp; pRet-&gt;initWithItems(item, args))
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L153">
      <a href="#L153">153</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L154">
      <a href="#L154">154</a>
    </th>
    <td class="line-code">
      <pre>                pRet-&gt;autorelease();
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L155">
      <a href="#L155">155</a>
    </th>
    <td class="line-code">
      <pre>                va_end(args);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L156">
      <a href="#L156">156</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">return</span> pRet;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L157">
      <a href="#L157">157</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L158">
      <a href="#L158">158</a>
    </th>
    <td class="line-code">
      <pre>        va_end(args);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L159">
      <a href="#L159">159</a>
    </th>
    <td class="line-code">
      <pre>        CC_SAFE_DELETE(pRet)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L160">
      <a href="#L160">160</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">return</span> <span class="predefined-constant">NULL</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L161">
      <a href="#L161">161</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L162">
      <a href="#L162">162</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L163">
      <a href="#L163">163</a>
    </th>
    <td class="line-code">
      <pre>CCMenuSlider* CCMenuSlider::menuWithItem(CCMenuItemSlider* item)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L164">
      <a href="#L164">164</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L165">
      <a href="#L165">165</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">return</span> menuWithItems(item, <span class="predefined-constant">NULL</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L166">
      <a href="#L166">166</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L167">
      <a href="#L167">167</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L168">
      <a href="#L168">168</a>
    </th>
    <td class="line-code">
      <pre><span class="directive">void</span> CCMenuSlider::ccTouchMoved(CCTouch* touch, <span class="local-variable">CCEvent</span>* event)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L169">
      <a href="#L169">169</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L170">
      <a href="#L170">170</a>
    </th>
    <td class="line-code">
      <pre>        CCMenuItemSlider *currentItem = (CCMenuItemSlider*)itemForTouch(touch);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L171">
      <a href="#L171">171</a>
    </th>
    <td class="line-code">
      <pre>        
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L172">
      <a href="#L172">172</a>
    </th>
    <td class="line-code">
      <pre>        <span class="local-variable">CCPoint</span> touchLocation = m_pSelectedItem-&gt;convertTouchToNodeSpace(touch);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L173">
      <a href="#L173">173</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L174">
      <a href="#L174">174</a>
    </th>
    <td class="line-code">
      <pre>        ((CCMenuItemSlider*)m_pSelectedItem)-&gt;dragToPoint(touchLocation);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L175">
      <a href="#L175">175</a>
    </th>
    <td class="line-code">
      <pre>        
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L176">
      <a href="#L176">176</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L177">
      <a href="#L177">177</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L178">
      <a href="#L178">178</a>
    </th>
    <td class="line-code">
      <pre><span class="predefined-type">bool</span> CCMenuSlider::ccTouchBegan(CCTouch* touch, <span class="local-variable">CCEvent</span>* event)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L179">
      <a href="#L179">179</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L180">
      <a href="#L180">180</a>
    </th>
    <td class="line-code">
      <pre>        CC_UNUSED_PARAM(event);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L181">
      <a href="#L181">181</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (m_eState != kCCMenuStateWaiting || ! m_bIsVisible)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L182">
      <a href="#L182">182</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L183">
      <a href="#L183">183</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">return</span> <span class="predefined-constant">false</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L184">
      <a href="#L184">184</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L185">
      <a href="#L185">185</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L186">
      <a href="#L186">186</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">for</span> (<span class="local-variable">CCNode</span> *c = <span class="directive">this</span>-&gt;m_pParent; c != <span class="predefined-constant">NULL</span>; c = c-&gt;getParent())
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L187">
      <a href="#L187">187</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L188">
      <a href="#L188">188</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">if</span> (c-&gt;getIsVisible() == <span class="predefined-constant">false</span>)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L189">
      <a href="#L189">189</a>
    </th>
    <td class="line-code">
      <pre>                {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L190">
      <a href="#L190">190</a>
    </th>
    <td class="line-code">
      <pre>                        <span class="keyword">return</span> <span class="predefined-constant">false</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L191">
      <a href="#L191">191</a>
    </th>
    <td class="line-code">
      <pre>                }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L192">
      <a href="#L192">192</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L193">
      <a href="#L193">193</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L194">
      <a href="#L194">194</a>
    </th>
    <td class="line-code">
      <pre>        CCMenuItemSlider *currentItem = itemForTouch(touch);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L195">
      <a href="#L195">195</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (currentItem)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L196">
      <a href="#L196">196</a>
    </th>
    <td class="line-code">
      <pre>        {   
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L197">
      <a href="#L197">197</a>
    </th>
    <td class="line-code">
      <pre>                m_pSelectedItem = currentItem;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L198">
      <a href="#L198">198</a>
    </th>
    <td class="line-code">
      <pre>                m_eState = kCCMenuStateTrackingTouch;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L199">
      <a href="#L199">199</a>
    </th>
    <td class="line-code">
      <pre>                currentItem-&gt;selected();                
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L200">
      <a href="#L200">200</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L201">
      <a href="#L201">201</a>
    </th>
    <td class="line-code">
      <pre>                <span class="local-variable">CCPoint</span> touchLocation = currentItem-&gt;convertTouchToNodeSpace(touch);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L202">
      <a href="#L202">202</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L203">
      <a href="#L203">203</a>
    </th>
    <td class="line-code">
      <pre>                currentItem-&gt;dragToPoint(touchLocation);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L204">
      <a href="#L204">204</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L205">
      <a href="#L205">205</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">return</span> <span class="predefined-constant">true</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L206">
      <a href="#L206">206</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L207">
      <a href="#L207">207</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">return</span> <span class="predefined-constant">false</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L208">
      <a href="#L208">208</a>
    </th>
    <td class="line-code">
      <pre>}
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L209">
      <a href="#L209">209</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L210">
      <a href="#L210">210</a>
    </th>
    <td class="line-code">
      <pre>CCMenuItemSlider* CCMenuSlider::itemForTouch(CCTouch * touch)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L211">
      <a href="#L211">211</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L212">
      <a href="#L212">212</a>
    </th>
    <td class="line-code">
      <pre>        <span class="local-variable">CCPoint</span> touchLocation = touch-&gt;locationInView(touch-&gt;view());
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L213">
      <a href="#L213">213</a>
    </th>
    <td class="line-code">
      <pre>        touchLocation = <span class="local-variable">CCDirector</span>::sharedDirector()-&gt;convertToGL(touchLocation);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L214">
      <a href="#L214">214</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L215">
      <a href="#L215">215</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">if</span> (m_pChildren &amp;&amp; m_pChildren-&gt;count() &gt; <span class="integer">0</span>)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L216">
      <a href="#L216">216</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L217">
      <a href="#L217">217</a>
    </th>
    <td class="line-code">
      <pre>                <span class="local-variable">CCObject</span>* pObject = <span class="predefined-constant">NULL</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L218">
      <a href="#L218">218</a>
    </th>
    <td class="line-code">
      <pre>                CCARRAY_FOREACH(m_pChildren, pObject)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L219">
      <a href="#L219">219</a>
    </th>
    <td class="line-code">
      <pre>                {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L220">
      <a href="#L220">220</a>
    </th>
    <td class="line-code">
      <pre>                        <span class="local-variable">CCNode</span>* pChild = (<span class="local-variable">CCNode</span>*) pObject;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L221">
      <a href="#L221">221</a>
    </th>
    <td class="line-code">
      <pre>                        <span class="keyword">if</span> (pChild &amp;&amp; pChild-&gt;getIsVisible() &amp;&amp; ((<span class="local-variable">CCMenuItem</span>*)pChild)-&gt;getIsEnabled())
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L222">
      <a href="#L222">222</a>
    </th>
    <td class="line-code">
      <pre>                        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L223">
      <a href="#L223">223</a>
    </th>
    <td class="line-code">
      <pre>                                <span class="local-variable">CCPoint</span> local = pChild-&gt;convertToNodeSpace(touchLocation);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L224">
      <a href="#L224">224</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L225">
      <a href="#L225">225</a>
    </th>
    <td class="line-code">
      <pre>                                CCMenuItemSlider* pItemSlider = (CCMenuItemSlider*)pChild;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L226">
      <a href="#L226">226</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L227">
      <a href="#L227">227</a>
    </th>
    <td class="line-code">
      <pre>                                <span class="local-variable">CCRect</span> r = <span class="local-variable">CCRectMake</span>(pItemSlider-&gt;getKnobImage()-&gt;getPosition().x - pItemSlider-&gt;getKnobImage()-&gt;getContentSize().width/<span class="integer">2</span>, 
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L228">
      <a href="#L228">228</a>
    </th>
    <td class="line-code">
      <pre>                                                          pItemSlider-&gt;getKnobImage()-&gt;getPosition().y - pItemSlider-&gt;getKnobImage()-&gt;getContentSize().height/<span class="integer">2</span>,
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L229">
      <a href="#L229">229</a>
    </th>
    <td class="line-code">
      <pre>                                                          pItemSlider-&gt;getKnobImage()-&gt;getContentSize().width, pItemSlider-&gt;getKnobImage()-&gt;getContentSize().height);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L230">
      <a href="#L230">230</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L231">
      <a href="#L231">231</a>
    </th>
    <td class="line-code">
      <pre>                                <span class="keyword">if</span> (<span class="local-variable">CCRect</span>::CCRectContainsPoint(r, local))
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L232">
      <a href="#L232">232</a>
    </th>
    <td class="line-code">
      <pre>                                {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L233">
      <a href="#L233">233</a>
    </th>
    <td class="line-code">
      <pre>                                        <span class="keyword">return</span> (CCMenuItemSlider*)pChild;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L234">
      <a href="#L234">234</a>
    </th>
    <td class="line-code">
      <pre>                                }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L235">
      <a href="#L235">235</a>
    </th>
    <td class="line-code">
      <pre>                        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L236">
      <a href="#L236">236</a>
    </th>
    <td class="line-code">
      <pre>                }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L237">
      <a href="#L237">237</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L238">
      <a href="#L238">238</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L239">
      <a href="#L239">239</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L240">
      <a href="#L240">240</a>
    </th>
    <td class="line-code">
      <pre>        <span class="keyword">return</span> <span class="predefined-constant">NULL</span>;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L241">
      <a href="#L241">241</a>
    </th>
    <td class="line-code">
      <pre>}</pre>
    </td>
  </tr>
  

</tbody>
</table>
</div>




 
        
      </div>
    
    <div class="cls h40"></div>
  

  <div id="ajax-indicator" style="display:none;"><span>Loading...</span></div>
  
  </div>
  <div class="foot">
  <div class="w960">
    <div class="copy">
      <p>
        Copyright &copy; 2010 - 2013 Cocos2d-x.org<a href="http://www3.clustrmaps.com/counter/maps.php?url=http://www.cocos2d-x.org" target="_blank"><img alt="Clustrmaps" src="http://files.cocos2d-x.org/images/orgsite/clustrmaps.jpg?1381483520" /></a>
      </p>
    </div>
    <div class="share"><em>Follow us:</em><a href="https://www.facebook.com/cocos2dx" class="link-f01"></a><a href="https://twitter.com/cocos2dx/" class="link-f02"></a><a href="http://www.weibo.com/cocos2dx" class="link-f03"></a></div>
  </div>
  <div id="goTop"></div>
</div>


<script type="text/javascript">
jQuery(document).ready(function() {
  var  $goTop = jQuery('#goTop');
	var  $top=jQuery('#goTop');
  $top.click(function() {
    jQuery("html, body").animate({ scrollTop: 0 }, 500);
  });
		
	$backToTopFun = function() {
	  var st = jQuery(document).scrollTop(), winh = jQuery(window).height();
	  (st > 50)? $goTop.show().stop().animate({opacity:1},500): $goTop.stop().animate({opacity:0},500);
	  if (jQuery.browser.version=="6.0") {	$goTop.css("position","absolute"); $goTop.css("top", st + winh - 330);}

  };
  jQuery(window).bind("scroll", $backToTopFun);
  jQuery(function() { $backToTopFun(); });
});
</script>


</body>
</html>

<script type="text/javascript">
jQuery(document).ready(function() {
  jQuery.timeago.settings.allowFuture = true;
  jQuery("abbr.timeago").timeago();
});
</script>
