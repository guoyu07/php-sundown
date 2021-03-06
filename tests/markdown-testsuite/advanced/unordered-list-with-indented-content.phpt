--TEST--
Check for unordered-list-with-indented-content
--SKIPIF--
<?php if (!extension_loaded("sundown")) print "skip"; ?>
<?php if (!extension_loaded("tidy")) print "skip"; ?>
--FILE--
<?php
$data = <<< DATA
*   This is a list item
    with the conten on
    multiline and indented.
*   And this another list item
    with the same principle.
DATA;
$md = new Sundown\Markdown(new Sundown\Render\Html());
$result = $md->render($data);

$tidy = new tidy;
$tidy->parseString($result, array("show-body-only"=>1));
$tidy->cleanRepair();
echo (string)$tidy;
--EXPECT--
<ul>
<li>This is a list item with the conten on multiline and
indented.</li>
<li>And this another list item with the same principle.</li>
</ul>
