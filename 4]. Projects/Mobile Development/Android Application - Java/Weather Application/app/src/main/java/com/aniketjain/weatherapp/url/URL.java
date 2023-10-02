package com.aniketjain.weatherapp.url;

import com.aniketjain.weatherapp.location.LocationCord;

public class URL {
    private String link;
    private static String city_url;

    public URL() {
        link = "https://api.openweathermap.org/data/2.5/onecall?exclude=minutely&lat="
                + LocationCord.lat + "&lon=" + LocationCord.lon + "&appid=" + LocationCord.API_KEY;
    }

    public String getLink() {
        return link;
    }


    public static void setCity_url(String cityName) {
        city_url = "https://api.openweathermap.org/data/2.5/weather?&q=" + cityName + "&appid=" + LocationCord.API_KEY;
    }

    public static String getCity_url() {
        return city_url;
    }

}