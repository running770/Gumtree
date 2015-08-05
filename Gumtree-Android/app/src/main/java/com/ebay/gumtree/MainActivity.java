package com.ebay.gumtree;

import android.app.SearchManager;
import android.content.Context;
import android.content.Intent;
import android.os.Handler;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AbsListView;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListAdapter;
import android.widget.ListView;
import android.widget.SearchView;

import com.gumtree.jni.GTAd;
import com.gumtree.jni.GTAdQuery;
import com.gumtree.jni.GTAdQueryRequest;
import com.gumtree.jni.GTAdQueryResponse;


public class MainActivity extends ActionBarActivity {

    private final static String TAG = "MainActivity";

    private ListView mListView;

    private GTAdQueryRequest mQueryRequest;
    private GTAdQuery mQuerySession;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        System.loadLibrary("PocoFoundation");
        System.loadLibrary("PocoJSON");
        System.loadLibrary("PocoNet");
        System.loadLibrary("GumtreeNet");

        mQueryRequest = new GTAdQueryRequest();

        mQueryRequest.setSize(10);
        mQueryRequest.setQ("baby");
        mQueryRequest.setPage(0);
        mQueryRequest.setMinPrice(1);
        mQueryRequest.setMaxPrice(1000);
        mQueryRequest.setSortType("PRICE_ASCENDING");
        mQueryRequest.setPictureRequired(true);

        mQuerySession = new GTAdQuery();

        GTAdQueryResponse response = new GTAdQueryResponse();
        mQuerySession.query(mQueryRequest, response);

        Log.d("MainActivity", "num of ad:" + response.getAds().size());


        mListView = (ListView)findViewById(R.id.listView);

//        mListView.setTextFilterEnabled(true);
//        mListView.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, mStrings));
        mListView.setTextFilterEnabled(true);

        mListView.setAdapter(new GTAdListAdapter(this, response.getAds()));

        mListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Log.d(TAG, "onItemClick " + "position:" + position + " rowId:" + id);
                GTAdListAdapter adapter = (GTAdListAdapter) mListView.getAdapter();

                startWebView((GTAd) adapter.getItem(position));
            }
        });

        mListView.setOnScrollListener(new AbsListView.OnScrollListener() {

            private int mLastItem;
            @Override
            public void onScrollStateChanged(AbsListView view, int scrollState) {

            }

            @Override
            public void onScroll(AbsListView view, int firstVisibleItem, int visibleItemCount, int totalItemCount) {
                int lastItm = firstVisibleItem + visibleItemCount;
                if (lastItm >= totalItemCount){
                    if (mLastItem != lastItm){

                        queryNextPage();

                        mLastItem = lastItm;
                    }
                }
            }
        });
    }

    public void startWebView(GTAd ad) {

        Intent intent = new Intent(MainActivity.this, GTAdWebView.class);
        String url = ad.getSelf_public_website();
        intent.putExtra(GTAdWebView.EXTRA_URL, url);
        Log.d(TAG, "open webview with url:" + url);
        startActivity(intent);

    }

    public void queryNextPage() {


        Handler handler = new Handler(getMainLooper());

        handler.post(new Runnable() {
            @Override
            public void run() {
                Log.d(TAG, "query next page...");
                mQueryRequest = mQueryRequest.requestForNextPage();

                GTAdQueryResponse response = new GTAdQueryResponse();
                mQuerySession.query(mQueryRequest, response);

                GTAdListAdapter adapter = (GTAdListAdapter) mListView.getAdapter();
                adapter.addItems(response.getAds());
            }
        });

    }

    public void queryNewKeyword(final String query) {
        Handler handler = new Handler(getMainLooper());

        handler.post(new Runnable() {
            @Override
            public void run() {
                Log.d(TAG, "query new key word:" + query);
                mQueryRequest.setQ(query);

                GTAdQueryResponse response = new GTAdQueryResponse();
                mQuerySession.query(mQueryRequest, response);

                GTAdListAdapter adapter = (GTAdListAdapter) mListView.getAdapter();
                adapter.setItems(response.getAds());
            }
        });
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.menu_main, menu);

        // Associate searchable configuration with the SearchView
        final SearchView searchView = (SearchView) menu.findItem(R.id.action_search).getActionView();

        if (null != searchView){
            searchView.setOnQueryTextListener(new SearchView.OnQueryTextListener() {
                @Override
                public boolean onQueryTextSubmit(String query) {

                    Log.d(TAG, "submitted query text:" + query);
                    queryNewKeyword(query);
                    return true;
                }

                @Override
                public boolean onQueryTextChange(String newText) {
                    return false;
                }
            });
        }


        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_settings) {
            return true;
        }
        else if (id == R.id.action_search){

            return true;

        }


        return super.onOptionsItemSelected(item);
    }
}
