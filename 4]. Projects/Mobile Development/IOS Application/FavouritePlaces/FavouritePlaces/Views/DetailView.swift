//
//  DetailView.swift
//  FavouritePlaces
//
//  Created by Anuj Khurana on 26/4/2023.
//

import SwiftUI
import CoreData
import MapKit
import CoreLocation

struct DetailView: View {
    
    @ObservedObject var place: Places
    
    @State var location = ""
    @State var desc = ""
    @State var latitude = ""
    @State var longitude = ""
    @State var url = ""
    @State var image = defaultImage
    
    /// - Parameters:
    ///   - description:An observed object representing a desc instance.
    ///   - location: A state variable holding the location details of the place.
    ///   - url: A state variable holding the url details of a landmark in a place.
    ///   - longitude: A state variable holding the longitude of the place.
    ///   - latitude: A state variable holding the latitude of the place.
    ///   - image: A state variable holding the image associated with a landmark of the place.
    ///   - region: A state variable holding the coordinate region for the map view. It is used to specify the centre and span of the map view.
    
    @Environment(\.editMode) var editMode
    
    @State var region = MKCoordinateRegion(center: CLLocationCoordinate2D(latitude:1, longitude: 1), span: MKCoordinateSpan(latitudeDelta: 0.1, longitudeDelta: 0.1 ))
     
    var body: some View {
        VStack{
            if (editMode?.wrappedValue == .inactive) {
                List {
                    //display small image (noimage) if no url
                    if (url == ""){ image.frame(width: 15,height: 15) }
                    else { image.scaledToFit().cornerRadius(12) }
                    
                    Text("Location Description:").font(.title2).foregroundColor(.accentColor)
                    Text("\(desc)").font(.title2).fontWeight(.medium)
                    Text("Map:").font(.title2).foregroundColor(.accentColor)
                    
                        NavigationLink(destination: MapView(place: place)) {
                            Map(coordinateRegion: $region) // display small map
                            Text("Map of \(location)").font(.title3).fontWeight(.medium)
                        }
                }
                HStack{
                    Image(systemName: "sunrise")
                    place.SunriseView
                    Spacer()
                    Image(systemName: "sunrise.fill")
                    place.SunsetView
                }.padding()
            }
            else {
                List{
//                    url for image
                    Text("Enter Url:").font(.title3).foregroundColor(.accentColor)
                    TextField("Url:", text: $url).font(.title3).fontWeight(.medium)
//                    image from url
                    image.scaledToFit().cornerRadius(12)
//                      location name
                    Text("Enter Locaion:").font(.title2).foregroundColor(.accentColor)
                    TextField("location:", text: $location).font(.title2).fontWeight(.medium)
//                    location description
                    Text("Enter Location details:").font(.title3).foregroundColor(.accentColor)
                    TextField("Location details ", text: $desc).font(.title3).fontWeight(.medium).frame(height: 50)
                }

            }// end else, in edit mode
        }.navigationTitle(location)
        .navigationBarItems(trailing: EditButton())
        .onAppear{
            region.center.latitude = place.latitude
            region.center.longitude = place.longitude
            location = place.strLocation
            desc = place.strDesc
            latitude = place.strLatitude
            longitude = place.strLongitude
            url = place.strUrl
            saveData()
        }
        .onDisappear{
            place.strLocation = location
            place.strUrl = url
            place.strDesc = desc
            saveData() // to save data in Places model
        }
        .task {
            await image = place.getImage()
            place.fetchTimeZone()
            place.fetchSunriseSunset()
        }
    }
}
