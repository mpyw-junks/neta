<?php

function h($str)
{
    return htmlspecialchars($str, ENT_QUOTES, 'UTF-8');
}

$file = new SplFileObject('kuimono.csv');
$file->setFlags(
    SplFileObject::READ_CSV |
    SplFileObject::READ_AHEAD |
    SplFileObject::SKIP_EMPTY |
    SplFileObject::DROP_NEW_LINE
);
$rows = iterator_to_array($file);
$header = array_shift($rows);
$groups = array_chunk($rows, 2);
array_unshift($groups, [$header]);

?>
<!DOCTYPE html>

<meta charset="UTF-8">
<title>2行ごとの分割テーブル</title>

<style>
body {
    background: #A9F5A9;
}
caption {
    caption-side: bottom;
    text-align: left;
}
table, td {
    border: solid 1px black;
}
table {
    border-collapse: collapse;
    margin: 10px;
}
td {
    background: white;
    padding: 10px;
}
</style>

<?php foreach ($groups as $i => $rows): ?>
<table>
    <caption>↑<?=h($i === 0 ? '各セルの題目' : "グループ$i")?></caption>
<?php foreach ($rows as $row): ?>
    <tr>
<?php foreach ($row as $cell): ?>
        <td><?=h($cell)?></td>
<?php endforeach; ?>
    </tr>
<?php endforeach; ?>
</table>
<?php endforeach; ?>
