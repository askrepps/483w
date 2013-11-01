<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en">
<head>
<meta http-equiv="content-type" content="text/html; charset=utf-8" />
<title>CCMenuItemSlider.h | Cocos2d-x</title>
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
try{if (!window.CloudFlare) { var CloudFlare=[{verbose:0,p:0,byc:0,owlid:"cf",bag2:1,mirage2:0,oracle:0,paths:{cloudflare:"/cdn-cgi/nexp/abv=2980380653/"},atok:"d7d12ab6e47ebd18df436caeb22a79f2",petok:"76e89ef2e1452c72c1b4c80c6f269f3f-1383269816-1800",zone:"cocos2d-x.org",rocket:"0",apps:{"ga_key":{"ua":"UA-3216502-3","ga_bs":"2"},"vig_key":{"sid":"d654e26afef9085d79aba37dfe97be28"}}}];var a=document.createElement("script"),b=document.getElementsByTagName("script")[0];a.async=!0;a.src="//ajax.cloudflare.com/cdn-cgi/nexp/abv=616370820/cloudflare.min.js";b.parentNode.insertBefore(a,b);}}catch(e){};
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
        
        <h2>CCMenuItemSlider.h</h2>

<div class="attachments">
<p>
   <span class="author"><a href="/users/399" class="blue">Songyuan Zhao</a>, 2011-12-13 05:28</span></p>
<p><a href="/attachments/download/668/CCMenuItemSlider.h">Download</a>   <span class="size">(2.5 kB)</span></p>

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
      <pre><span class="comment">/****************************************************************************
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L2">
      <a href="#L2">2</a>
    </th>
    <td class="line-code">
      <pre>Copyright (c) Sonic Zhao | weibo:http://weibo.com/transong
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L3">
      <a href="#L3">3</a>
    </th>
    <td class="line-code">
      <pre>Objc version authro pmanna | links:http://www.cocos2d-iphone.org/wiki/doku.php/tips:slider_widget
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L4">
      <a href="#L4">4</a>
    </th>
    <td class="line-code">
      <pre>*/</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L5">
      <a href="#L5">5</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L6">
      <a href="#L6">6</a>
    </th>
    <td class="line-code">
      <pre><span class="preprocessor">#ifndef</span> __CCMENU_ITEM_SLIDER_H__
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L7">
      <a href="#L7">7</a>
    </th>
    <td class="line-code">
      <pre><span class="preprocessor">#define</span> __CCMENU_ITEM_SLIDER_H__
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
      <pre><span class="preprocessor">#include</span> <span class="include">&quot;CCMenu.h&quot;</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L10">
      <a href="#L10">10</a>
    </th>
    <td class="line-code">
      <pre><span class="preprocessor">#include</span> <span class="include">&quot;CCLabelTTF.h&quot;</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L11">
      <a href="#L11">11</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L12">
      <a href="#L12">12</a>
    </th>
    <td class="line-code">
      <pre>using namespace cocos2d;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L13">
      <a href="#L13">13</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L14">
      <a href="#L14">14</a>
    </th>
    <td class="line-code">
      <pre>class CCMenuItemSlider : public CCMenuItem, public CCRGBAProtocol
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L15">
      <a href="#L15">15</a>
    </th>
    <td class="line-code">
      <pre>{
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
      <pre><span class="label">public:</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L18">
      <a href="#L18">18</a>
    </th>
    <td class="line-code">
      <pre>        <span class="comment">//properties</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L19">
      <a href="#L19">19</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> setMinValue(<span class="predefined-type">float</span> minV){ m_minValue = minV; }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L20">
      <a href="#L20">20</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> setMaxValue(<span class="predefined-type">float</span> maxV){ m_maxValue = maxV; }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L21">
      <a href="#L21">21</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> setValue(<span class="predefined-type">float</span> v);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L22">
      <a href="#L22">22</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L23">
      <a href="#L23">23</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span> getMinValue(){ <span class="keyword">return</span> m_minValue; }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L24">
      <a href="#L24">24</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span> getMaxValue(){ <span class="keyword">return</span> m_maxValue; }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L25">
      <a href="#L25">25</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span> getValue(){ <span class="keyword">return</span> m_value; }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L26">
      <a href="#L26">26</a>
    </th>
    <td class="line-code">
      <pre>        CCNode* getKnobImage(){ <span class="keyword">return</span> m_knobImage; }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L27">
      <a href="#L27">27</a>
    </th>
    <td class="line-code">
      <pre>    <span class="comment">//</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L28">
      <a href="#L28">28</a>
    </th>
    <td class="line-code">
      <pre>    
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L29">
      <a href="#L29">29</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> selected()
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L30">
      <a href="#L30">30</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L31">
      <a href="#L31">31</a>
    </th>
    <td class="line-code">
      <pre>                m_knobImage-&gt;convertToRGBAProtocol()-&gt;setColor(ccc3(<span class="integer">150</span>,<span class="integer">150</span>,<span class="integer">150</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L32">
      <a href="#L32">32</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L33">
      <a href="#L33">33</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> unselected()
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L34">
      <a href="#L34">34</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L35">
      <a href="#L35">35</a>
    </th>
    <td class="line-code">
      <pre>                m_knobImage-&gt;convertToRGBAProtocol()-&gt;setColor(ccc3(<span class="integer">255</span>,<span class="integer">255</span>,<span class="integer">255</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L36">
      <a href="#L36">36</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L37">
      <a href="#L37">37</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> setIsEnabled(<span class="predefined-type">bool</span> bEnabled)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L38">
      <a href="#L38">38</a>
    </th>
    <td class="line-code">
      <pre>        {
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L39">
      <a href="#L39">39</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L40">
      <a href="#L40">40</a>
    </th>
    <td class="line-code">
      <pre>                m_bIsEnabled = bEnabled;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L41">
      <a href="#L41">41</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">if</span>(bEnabled)
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L42">
      <a href="#L42">42</a>
    </th>
    <td class="line-code">
      <pre>                        setColor(ccc3(<span class="integer">255</span>,<span class="integer">255</span>,<span class="integer">255</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L43">
      <a href="#L43">43</a>
    </th>
    <td class="line-code">
      <pre>                <span class="keyword">else</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L44">
      <a href="#L44">44</a>
    </th>
    <td class="line-code">
      <pre>                        setColor(ccc3(<span class="integer">200</span>,<span class="integer">200</span>,<span class="integer">200</span>));
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L45">
      <a href="#L45">45</a>
    </th>
    <td class="line-code">
      <pre>        }
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L46">
      <a href="#L46">46</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L47">
      <a href="#L47">47</a>
    </th>
    <td class="line-code">
      <pre>        <span class="comment">//RGBAProtocol</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L48">
      <a href="#L48">48</a>
    </th>
    <td class="line-code">
      <pre>    <span class="directive">void</span> setColor(<span class="directive">const</span> ccColor3B&amp; color);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L49">
      <a href="#L49">49</a>
    </th>
    <td class="line-code">
      <pre>    <span class="directive">const</span> ccColor3B&amp; getColor(<span class="directive">void</span>);
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
      <pre>        GLubyte getOpacity(<span class="directive">void</span>);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L52">
      <a href="#L52">52</a>
    </th>
    <td class="line-code">
      <pre>    <span class="directive">void</span> setOpacity(GLubyte opacity);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L53">
      <a href="#L53">53</a>
    </th>
    <td class="line-code">
      <pre>    <span class="comment">//</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L54">
      <a href="#L54">54</a>
    </th>
    <td class="line-code">
      <pre>    <span class="comment">//the reason to use CCNode instead of string is it's efficient to generate a ccsprite from a spritesheet</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L55">
      <a href="#L55">55</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">static</span> CCMenuItemSlider* itemFromNormalSprite(CCNode* trackSprite, CCNode* knobSprite);        
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L56">
      <a href="#L56">56</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">static</span> CCMenuItemSlider* itemFromNormalSprite(CCNode* trackSprite, CCNode* knobSprite, SelectorProtocol* target, SEL_MenuHandler selector);        
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L57">
      <a href="#L57">57</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">bool</span> initFromNormalSprite(CCNode* trackSprite, CCNode* knobSprite, SelectorProtocol* target, SEL_MenuHandler selector);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L58">
      <a href="#L58">58</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L59">
      <a href="#L59">59</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">void</span> dragToPoint(CCPoint aPoint);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L60">
      <a href="#L60">60</a>
    </th>
    <td class="line-code">
      <pre><span class="label">protected:</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L61">
      <a href="#L61">61</a>
    </th>
    <td class="line-code">
      <pre><span class="label">private:</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L62">
      <a href="#L62">62</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span>                        m_minValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L63">
      <a href="#L63">63</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span>                        m_maxValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L64">
      <a href="#L64">64</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">float</span>                        m_value;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L65">
      <a href="#L65">65</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L66">
      <a href="#L66">66</a>
    </th>
    <td class="line-code">
      <pre>        <span class="predefined-type">bool</span>                        m_isVertical;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L67">
      <a href="#L67">67</a>
    </th>
    <td class="line-code">
      <pre>    
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L68">
      <a href="#L68">68</a>
    </th>
    <td class="line-code">
      <pre>        CCNode*         m_trackImage;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L69">
      <a href="#L69">69</a>
    </th>
    <td class="line-code">
      <pre>        CCNode*         m_knobImage;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L70">
      <a href="#L70">70</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L71">
      <a href="#L71">71</a>
    </th>
    <td class="line-code">
      <pre>        <span class="comment">//you can remove it if you like</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L72">
      <a href="#L72">72</a>
    </th>
    <td class="line-code">
      <pre>        CCLabelTTF*     m_labelValue;
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L73">
      <a href="#L73">73</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L74">
      <a href="#L74">74</a>
    </th>
    <td class="line-code">
      <pre>};
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L75">
      <a href="#L75">75</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L76">
      <a href="#L76">76</a>
    </th>
    <td class="line-code">
      <pre>class CCMenuSlider : public CCMenu
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L77">
      <a href="#L77">77</a>
    </th>
    <td class="line-code">
      <pre>{
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L78">
      <a href="#L78">78</a>
    </th>
    <td class="line-code">
      <pre><span class="label">public:</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L79">
      <a href="#L79">79</a>
    </th>
    <td class="line-code">
      <pre>    
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L80">
      <a href="#L80">80</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">static</span> CCMenuSlider* menuWithItems(CCMenuItemSlider* item, ...);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L81">
      <a href="#L81">81</a>
    </th>
    <td class="line-code">
      <pre>        <span class="directive">static</span> CCMenuSlider*menuWithItem(CCMenuItemSlider* item);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L82">
      <a href="#L82">82</a>
    </th>
    <td class="line-code">
      <pre>    
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L83">
      <a href="#L83">83</a>
    </th>
    <td class="line-code">
      <pre>        virtual <span class="predefined-type">bool</span> ccTouchBegan(CCTouch* touch, CCEvent* event);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L84">
      <a href="#L84">84</a>
    </th>
    <td class="line-code">
      <pre>        virtual <span class="directive">void</span> ccTouchMoved(CCTouch* touch, CCEvent* event);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L85">
      <a href="#L85">85</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L86">
      <a href="#L86">86</a>
    </th>
    <td class="line-code">
      <pre>        CCMenuItemSlider* itemForTouch(CCTouch * touch);
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L87">
      <a href="#L87">87</a>
    </th>
    <td class="line-code">
      <pre><span class="label">protected:</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L88">
      <a href="#L88">88</a>
    </th>
    <td class="line-code">
      <pre><span class="label">private:</span>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L89">
      <a href="#L89">89</a>
    </th>
    <td class="line-code">
      <pre>};
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L90">
      <a href="#L90">90</a>
    </th>
    <td class="line-code">
      <pre>
</pre>
    </td>
  </tr>
  

  <tr>
    <th class="line-num" id="L91">
      <a href="#L91">91</a>
    </th>
    <td class="line-code">
      <pre><span class="preprocessor">#endif</span> <span class="comment">//__CCMENU_ITEM_SLIDER_H__</span></pre>
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
