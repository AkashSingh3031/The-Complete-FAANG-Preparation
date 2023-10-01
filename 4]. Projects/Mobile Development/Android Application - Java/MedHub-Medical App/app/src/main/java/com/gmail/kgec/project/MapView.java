package com.gmail.kgec.project;

import android.app.Dialog;
import android.content.Intent;
import android.location.Address;
import android.location.Geocoder;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v7.app.AppCompatActivity;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Toast;

import com.google.android.gms.common.ConnectionResult;
import com.google.android.gms.common.GoogleApiAvailability;
import com.google.android.gms.maps.CameraUpdate;
import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapFragment;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.MarkerOptions;

import java.io.IOException;
import java.util.List;

/**
 * Created by sourajit on 9/2/17.
 */

public class MapView extends AppCompatActivity implements OnMapReadyCallback {
    GoogleMap map;
    String location;
    String loc;
    StringBuffer sb;
    @Override

    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        if (google_service_avail()) {

            setContentView(R.layout.mapview);
            final MoreDetails hos;
            hos = (MoreDetails) getIntent().getSerializableExtra("pass");
            loc=hos.nm;
            sb=new StringBuffer(loc);
            sb.append(","+ hos.district+ hos.state);
            location=sb.toString();
           // Toast.makeText(getApplicationContext(), "Success.."+location, Toast.LENGTH_SHORT).show();
            initMap();
        }
    }
    private void initMap() {
        MapFragment mapFrag = (MapFragment) getFragmentManager().findFragmentById(R.id.map_fragment);
        mapFrag.getMapAsync(this);
    }

    private boolean google_service_avail() {
        GoogleApiAvailability api = GoogleApiAvailability.getInstance();
        int isAvail = api.isGooglePlayServicesAvailable(this);
        if (isAvail == ConnectionResult.SUCCESS) {
            return true;
        } else if (api.isUserResolvableError(isAvail)) {
            Dialog dialog = api.getErrorDialog(this, isAvail, 0);
            dialog.show();
        } else {
            Toast.makeText(getApplicationContext(), "Cant connect..", Toast.LENGTH_SHORT).show();
        }
        return false;
    }

    @Override
    public void onMapReady(GoogleMap googleMap) {
        double lat = 0, lng = 0;
        map = googleMap;

        int x=0;
        Geocoder gc=new Geocoder(this);
        try {
            List<Address> list = gc.getFromLocationName(location, 1);
            if(!list.isEmpty()) {

                Address add = list.get(0);

                lat = add.getLatitude();
                lng = add.getLongitude();
            }
            else{
                x=1;
            }


        } catch (IOException e) {
            Toast.makeText(getApplicationContext(),"No location",Toast.LENGTH_SHORT).show();
        }
        goToLocation(lat,lng,16);
        if(x==0) {
            MarkerOptions options = new MarkerOptions()
                    .title(location)
                    .position(new LatLng(lat, lng));
            map.addMarker(options);
        }
    }


    private void goToLocation(double lat, double lng,float zoom) {
        LatLng ll=new LatLng(lat,lng);
        CameraUpdate update= CameraUpdateFactory.newLatLngZoom(ll,zoom);
        map.moveCamera(update);


    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu,menu);
        return super.onCreateOptionsMenu(menu);
    }

    public boolean onOptionsItemSelected(MenuItem item){
        switch(item.getItemId()){
            case R.id.map_normal:
                map.setMapType(GoogleMap.MAP_TYPE_NORMAL);
                break;
            case R.id.map_satellite:
                map.setMapType(GoogleMap.MAP_TYPE_SATELLITE);
                break;
            case R.id.map_hybrid:
                map.setMapType(GoogleMap.MAP_TYPE_HYBRID);
                break;
        }
        return super.onOptionsItemSelected(item);
    }
}
