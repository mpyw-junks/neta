<?php

function h($str)
{
    return htmlspecialchars($str, ENT_QUOTES, 'UTF-8');
}

try {

    $pdo = new PDO('sqlite:tabemono.db', null, null, [
        PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
        PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
    ]);

    $groups = $pdo->query('
        SELECT iro, tabemono.* FROM tabemono
        ORDER BY id
    ')->fetchAll(PDO::FETCH_ASSOC|PDO::FETCH_GROUP);

} catch (PDOException $e) {

    header('Content-Type: text/plain; charset=UTF-8', true, 500);
    exit($e->getMessage());

}

?>
<!DOCTYPE html>

<meta charset="UTF-8">
<title>色ごとの分割テーブル</title>

<style>
body {
    background: #A9F5A9;
}
caption {
    caption-side: bottom;
    text-align: left;
}
caption::before {
    content: '↑';
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

<table>
    <caption>各セルの題目</caption>
    <tr>
        <td>番号</td>
        <td>名前</td>
        <td>色</td>
        <td>食感</td>
    </tr>
</table>

<?php foreach ($groups as $iro => $rows): ?>
<table>
    <caption><?=h($iro)?>色のグループ</caption>
<?php foreach ($rows as $row): ?>
    <tr>
<?php foreach ($row as $cell): ?>
        <td><?=h($cell)?></td>
<?php endforeach; ?>
    </tr>
<?php endforeach; ?>
</table>
<?php endforeach; ?>
