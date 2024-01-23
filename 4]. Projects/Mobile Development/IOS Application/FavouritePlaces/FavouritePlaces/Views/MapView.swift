//
//  MapRowView.swift
//  FavouritePlaces
//
//  Created by Anuj Khurana on 6/5/2023.
//

import SwiftUI
import MapKit


struct MapView: View {
    
    @State var latitude = ""
    @State var longitude = ""
    @State var location = ""
    @State var showAlert = false
    @ObservedObject var place: Places
    
    @State var region = MKCoordinateRegion(center: CLLocationCoordinate2D(latitude: 1, longitude: 1), span: MKCoordinateSpan(latitudeDelta: 0.5, longitudeDelta: 0.5))
    
    @Environment(\.editMode) var editMode
    
    /// - Parameters:
    ///   - location: A state variable holding the name of the location.
    ///   - longitude: A state variable holding the longitude of the place.
    ///   - latitude: A state variable holding the latitude of the place.
    ///   - region: A state variable holding the coordinate region for the map view. It is used to specify the centre and span of the map view.
    
    var body: some View {
        VStack{
            //outside edit mode
            if (editMode?.wrappedValue == .inactive){
                VStack{
                    ZStack{
                        Map(coordinateRegion: $region)}
                    
                    HStack{
                        Text("Latitude: ").font(.title3).foregroundColor(.accentColor)
                        Text("\(latitude)").font(.title3).fontWeight(.medium)
                    }
                    HStack{
                        Text("Longitude: ").font(.title3).foregroundColor(.accentColor)
                        Text("\(longitude)").font(.title3).fontWeight(.medium)}
                }
            //not in edit mode
            } else {
                VStack{
                    HStack{
                        Image(systemName: "magnifyingglass.circle")
                            .onTapGesture {
                                place.fromLocToAddress()
                                location=place.strLocation
                                saveData()
                            }
                        TextField("location name: ", text: $location)
                            .font(.title3)
                            .fontWeight(.medium)
                            .textFieldStyle(.roundedBorder)
                            .padding(.leading)
                    }.padding(.leading)
                    ZStack{
                        Map(coordinateRegion: $region)
                        }
                    HStack{
                        Image(systemName: "globe").foregroundColor(Color.blue)
                            .onTapGesture {
                                fromAddressToLoc()
                            }.padding(.leading)
                        VStack{
                            Text("Latitude: ").font(.title3).foregroundColor(.accentColor)
                            TextField("Latitude:",text: $region.Strlat)
                                .font(.title3)
                                .fontWeight(.medium)
                                .textFieldStyle(.roundedBorder)
                            .padding(.leading)}
                        VStack{
                            Text("Longitude: ").font(.title3).foregroundColor(.accentColor)
                            TextField("Longitude:",text: $region.Strlong)
                                .font(.title3)
                                .fontWeight(.medium)
                                .textFieldStyle(.roundedBorder)
                            .padding(.leading)}
                    }.padding(.trailing)
                }
                    .onChange(of: region) { _ in
                        place.strLocation=location
                        latitude = region.Strlat
                        longitude = region.Strlong
                        //to update changes
                    }
            } //end else
        }
        .navigationTitle("📍Map \(location)")
        .navigationBarItems(trailing: EditButton())
        .onAppear {
            latitude = place.strLatitude
            longitude = place.strLongitude
            location = place.strLocation
            saveData()
        }
        .onDisappear{
            place.strLongitude = longitude
            place.strLatitude = latitude
            region.center.longitude = place.longitude
            region.center.latitude = place.latitude
            saveData()
        }
        .task {
            place.updateMap()
            checkMap()
            
        }
    }
    /// function to checkmap and update
    func checkMap() {
        latitude = place.strLatitude
        longitude = place.strLongitude
        region.center.latitude = place.latitude
        region.center.longitude = place.longitude
    }
    func fromAddressToLoc() {
        let coder = CLGeocoder()
        coder.geocodeAddressString(location) { marks, error in
            if let err = error {
                print("errof in fromAddressToLoc \(err)")
                return
            }
            guard let pmk = marks?.first else {
                print("can't find primary placemark in address to loc")
                return
            }
            region.center.latitude = pmk.location?.coordinate.latitude ?? 0.0
            region.center.longitude = pmk.location?.coordinate.longitude ?? 0.0
        }
    }
}
