package com.wtndhu.xml_temp;

import android.app.AlertDialog;
import android.os.Bundle;
import android.support.design.widget.FloatingActionButton;
import android.support.design.widget.Snackbar;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.SimpleAdapter;
import android.widget.Spinner;
import android.content.DialogInterface;

import org.xmlpull.v1.XmlPullParser;
import org.xmlpull.v1.XmlPullParserException;
import org.xmlpull.v1.XmlPullParserFactory;

import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.HashMap;

import cz.msebera.android.httpclient.client.HttpClient;
import cz.msebera.android.httpclient.client.methods.HttpPost;
import cz.msebera.android.httpclient.impl.client.DefaultHttpClient;

/**
 * Created by WeiYu on 2016/1/4.
 */

public class wetr_main extends AppCompatActivity
{

    Spinner CityName;
    ListView listView;
    String SelectCityName;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        FloatingActionButton fab = (FloatingActionButton) findViewById(R.id.fab);
        fab.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Snackbar.make(view, "Replace with your own action", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
            }
        });

        CityName = (Spinner) findViewById(R.id.CityName);
        listView = (ListView) findViewById(R.id.listView1);
        CityName.setOnItemSelectedListener(CityNameSelect);

    }

    // Spinner 抓 String
    private AdapterView.OnItemSelectedListener CityNameSelect = new AdapterView.OnItemSelectedListener()
    {

        @Override
        public void onItemSelected(AdapterView<?> parent, View view, int position, long id)
        {
            SelectCityName = parent.getSelectedItem().toString();

            new Thread(new Runnable() {
                @Override
                public void run() {
                    try {
                        final ArrayList<HashMap<String, Object>> arrayList = parse();

                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                SimpleAdapter adapter = new SimpleAdapter(
                                        getApplicationContext(), arrayList,
                                        R.layout.list, new String[] { "startTime",
                                        "endTime", "parameterName",
                                        "parameterValue" }, new int[] {
                                        R.id.textView1, R.id.textView2,
                                        R.id.textView3, R.id.textView4 });
                                listView.setAdapter(adapter);
                            }
                        });

                    } catch (URISyntaxException e) {
                        e.printStackTrace();
                    }
                }
            }).start();
        }

        @Override
        public void onNothingSelected(AdapterView<?> parent) {}
    };

    public static InputStream getData(String url) throws URISyntaxException, IOException
    {
        HttpClient httpClient = new DefaultHttpClient();
        HttpPost post = new HttpPost( url );

        return httpClient.execute(post).getEntity().getContent();
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        switch(item.getItemId()) {
            case R.id.menu_about:
                AlertDialog.Builder bt = new AlertDialog.Builder(this);
                bt.setTitle("關於");
                bt.setMessage("製作者:陳韋佑");
                bt.setPositiveButton("確認", new DialogInterface.OnClickListener() {
                    public void onClick(DialogInterface dialog, int id) {
                    }
                });
                bt.show();
                break;
            case R.id.menu_quit:
                finish();
                break;
            default:
        }
        return super.onOptionsItemSelected(item);
    }


    public ArrayList<HashMap<String, Object>> parse() throws URISyntaxException
    {
        String tagName = null;
        String cityName = null;

        ArrayList<HashMap<String, Object>> arrayList = new ArrayList<HashMap<String, Object>>();
        HashMap<String, Object> hashMap = new HashMap<String, Object>();
        // 記錄出現次數
        int findCount = 0;
        try {
            // 定義工廠 XmlPullParserFactory
            XmlPullParserFactory factory = XmlPullParserFactory.newInstance();
            // 定義解析器 XmlPullParser
            XmlPullParser parser = factory.newPullParser();
            // //獲取xml輸入數據
            parser.setInput(new InputStreamReader(
                    wetr_main.getData("http://opendata.cwb.gov.tw/opendata/MFC/F-C0032-005.xml")));

            // 開始解析事件
            int eventType = parser.getEventType();
            // 處理事件，不碰到文檔結束就一直處理
            while (eventType != XmlPullParser.END_DOCUMENT) {
                // 因為XmlPullParser預先定義了一堆靜態常量，所以這裡可以用switch
                switch (eventType)
                {

                    case XmlPullParser.START_TAG:
                        // 給當前標籤起個名字
                        tagName = parser.getName();
                        // 看到感興趣的標籤個計數
                        if (findCount == 0 && tagName.equals("time")) {
                            findCount += 1;
                        }
                        break;

                    case XmlPullParser.TEXT:
                        if (tagName.equals("startTime") && hashMap.containsKey("startTime") == false)
                        {
                            String time = parser.getText();
                            hashMap.put("startTime", "StartTime: " + time.substring(0, 19).replace("T", "  "));
                        }
                        else if (tagName.equals("endTime") && hashMap.containsKey("endTime") == false)
                        {
                            String time = parser.getText();
                            hashMap.put("endTime", "EndTime  : " + time.substring(0,19).replace("T", "  "));
                        }
                        else if (tagName.equals("parameterName") && hashMap.containsKey("parameterName") == false)
                        {
                            hashMap.put("parameterName", "狀況：" + parser.getText());
                        }
                        else if (tagName.equals("parameterValue") && hashMap.containsKey("parameterValue") == false)
                        {
                            int time = Integer.parseInt(parser.getText()) * 5;
                            if(time>100) time = 100;
                            hashMap.put("parameterValue", "    降雨機率：" + time);
                        }
                        else if (tagName.equals("locationName") && hashMap.containsKey("locationName") == false)
                        {
                            cityName = parser.getText();
                            hashMap.put("locationName", cityName);
                        }
                        break;

                    case XmlPullParser.END_TAG:
                        // 嘗試取得當前標籤名稱，若是Data才可以增加到arrayList，並且重置
                        String trytagName = parser.getName();
                        if (trytagName.equals("time"))
                        {
                            tagName = parser.getName();
                            findCount = 0;
                            if(cityName.equals(SelectCityName))
                                arrayList.add(hashMap);
                            hashMap = new HashMap<String, Object>();
                        }
                        break;
                }
                // 別忘了一定要用next方法處理下一個事件，忘了的結果就成無窮環圈#_#
                eventType = parser.next();
            }
            return arrayList;
        } catch (XmlPullParserException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return arrayList;
    }
}