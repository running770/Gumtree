package com.ebay.gumtree;

import android.app.Activity;
import android.content.Context;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import com.gumtree.jni.GTAd;
import com.gumtree.jni.GTAdList;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.CopyOnWriteArrayList;

/**
 * Created by justinliu on 4/8/15.
 */
public class GTAdListAdapter extends BaseAdapter {

    private final static String TAG = "GTAdListAdapter";
    private Activity mParentActivity;


    private final List<GTAd> mAdList = new CopyOnWriteArrayList<GTAd>();


    private final ImageDownloader mImageDownloader = new ImageDownloader();

    public GTAdListAdapter(Activity parent, GTAdList adList) {
        mParentActivity = parent;

        addItems(adList);

        mImageDownloader.setMode(ImageDownloader.Mode.CORRECT);
    }

    public void addItems(GTAdList newList){
        for (int i = 0; i < newList.size(); i++) {
            mAdList.add(newList.get(i));
        }
    }

    public void setItems(GTAdList newList){
        mAdList.clear();
        addItems(newList);
    }

    @Override
    public int getCount() {
        return mAdList.size();
    }

    @Override
    public Object getItem(int position) {
        return mAdList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        View itemView = convertView;

        if (null == itemView){

            LayoutInflater inflater = (LayoutInflater)mParentActivity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

            itemView = inflater.inflate(R.layout.listview_item_gumtree_ad, null);
        }

        makeItemView(itemView, position);

        return itemView;
    }



    private View makeItemView(View itemView, int position) {

        GTAd ad = mAdList.get(position);
        String line1 = ad.getTitle();

        String line2 = "";
        double price = ad.getPrice().getAmount();
        if (0 != price) {
            line2 = ad.getPrice().getCurrency() + " :" + ad.getPrice().getAmount();
        }
        else {
            line2 = ad.getPrice().getType();
        }

        String imageUrl = null;
        if (ad.getNormalPicuteLinks().size() > 0){
            imageUrl = ad.getNormalPicuteLinks().get(0);
        }


        Log.d(TAG, "line1:" + line1);
        Log.d(TAG, "line2:" + line2);
        Log.d(TAG, "imageUrl:" + imageUrl);

        TextView viewTitle = (TextView) itemView.findViewById(R.id.listview_item_ad_line1);
        viewTitle.setText(line1);
        TextView viewText = (TextView) itemView.findViewById(R.id.listview_item_ad_line2);
        viewText.setText(line2);
        ImageView imageView = (ImageView) itemView.findViewById(R.id.listview_item_ad_imageView);

        if (null != imageUrl) {
            mImageDownloader.download(imageUrl, imageView);
        }

        return itemView;
    }
}
