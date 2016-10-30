<?php

function scrape_yjw_pinpoint_today($url)
{
    $ch = curl_init();
    curl_setopt_array($ch, [
        CURLOPT_URL => $url,
        CURLOPT_RETURNTRANSFER => true,
        CURLOPT_FAILONERROR => true,
    ]);
    $html = curl_exec($ch);

    if ($html === false) {
        return false;
    }

    $dom = new DOMDocument;
    libxml_use_internal_errors(true);
    $dom->loadHTML($html);
    libxml_clear_errors();
    $xpath = new DOMXPath($dom);

    $table = $xpath->query('//table[@class="yjw_table2"]')->item(0);

    if ($table === false) {
        return false;
    }

    $list = function (DOMNodeList $nodes) {
        return array_map(
            function (DOMNode $node) {
                return trim(str_replace(["\r", "\n"], '', $node->nodeValue));
            },
            iterator_to_array($nodes)
        );
    };

    $chart = [];
    foreach ($xpath->query('tr/td[1]', $table) as $i => $title) {
        $nodes = $xpath->query("tr[$i+1]/td[position()>1]", $table);
        if ($i === 0) {
            $timings = $list($nodes);
        } else {
            $chart[$title->nodeValue] = array_combine($timings, $list($nodes));
        }
    }

    return [
        '最終更新日時' => $xpath->evaluate('normalize-space(
            //p[@class="yjSt yjw_note_h2"]
        )'),
        '日付' => $xpath->evaluate('substring(
            //div[@id="yjw_pinpoint_today"]/h3/span[@class="yjSt"], 4
        )'),
        '情報' => $chart,
    ];
}

var_dump(scrape_yjw_pinpoint_today(
    'http://weather.yahoo.co.jp/weather/jp/34/6710/34101.html'
));

/*

array(3) {
  ["最終更新日時"]=>
  string(36) "2016年10月30日　22時00分発表"
  ["日付"]=>
  string(15) "10月30日(日)"
  ["情報"]=>
  array(5) {
    ["天気"]=>
    array(8) {
      ["0時"]=>
      string(6) "曇り"
      ["3時"]=>
      string(6) "曇り"
      ["6時"]=>
      string(6) "晴れ"
      ["9時"]=>
      string(6) "晴れ"
      ["12時"]=>
      string(6) "晴れ"
      ["15時"]=>
      string(6) "晴れ"
      ["18時"]=>
      string(6) "晴れ"
      ["21時"]=>
      string(6) "晴れ"
    }
    ["気温（℃）"]=>
    array(8) {
      ["0時"]=>
      string(2) "14"
      ["3時"]=>
      string(2) "13"
      ["6時"]=>
      string(2) "12"
      ["9時"]=>
      string(2) "14"
      ["12時"]=>
      string(2) "19"
      ["15時"]=>
      string(2) "19"
      ["18時"]=>
      string(2) "18"
      ["21時"]=>
      string(2) "15"
    }
    ["湿度（％）"]=>
    array(8) {
      ["0時"]=>
      string(2) "78"
      ["3時"]=>
      string(2) "81"
      ["6時"]=>
      string(2) "82"
      ["9時"]=>
      string(2) "64"
      ["12時"]=>
      string(2) "50"
      ["15時"]=>
      string(2) "52"
      ["18時"]=>
      string(2) "74"
      ["21時"]=>
      string(2) "85"
    }
    ["降水量（mm/h）"]=>
    array(8) {
      ["0時"]=>
      string(1) "0"
      ["3時"]=>
      string(1) "0"
      ["6時"]=>
      string(1) "0"
      ["9時"]=>
      string(1) "0"
      ["12時"]=>
      string(1) "0"
      ["15時"]=>
      string(1) "0"
      ["18時"]=>
      string(1) "0"
      ["21時"]=>
      string(1) "0"
    }
    ["風向風速（m/s）"]=>
    array(8) {
      ["0時"]=>
      string(10) "北北東4"
      ["3時"]=>
      string(10) "北北東2"
      ["6時"]=>
      string(10) "北北東3"
      ["9時"]=>
      string(10) "北北東2"
      ["12時"]=>
      string(10) "北北西2"
      ["15時"]=>
      string(7) "南西3"
      ["18時"]=>
      string(4) "西1"
      ["21時"]=>
      string(10) "北北東3"
    }
  }
}

*/