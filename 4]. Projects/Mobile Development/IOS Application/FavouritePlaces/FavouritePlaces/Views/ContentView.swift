//
//  ContentView.swift
//  FavouritePlaces
//
//  Created by Anuj Khurana on 26/4/2023.
//
import SwiftUI
import CoreData
import MapKit

struct ContentView: View {
    
    @Environment(\.managedObjectContext) var ctx
    @FetchRequest(sortDescriptors: []) var places : FetchedResults<Places>
    
    
    var body: some View {
        VStack {
            NavigationView {
                List {
                    ForEach(places) {
                        place in
                        NavigationLink(destination: DetailView(place: place)) {
                            RowView(place: place)
                        }
                        
                    }.onDelete { idx in
                        deletePlaces(idx)
                    }
                }.navigationTitle("Favourite Places 🌎")
                .navigationBarItems(leading: Button("+ Add"){addNewPlace()}, trailing: EditButton())
                Spacer()
            }
        }
        .task {
            if(places.count == 0) {
                loadDefaultData()
            }
        }
    }
    
    /// This function adds a new `Place` instance and saves it in the database.
    func addNewPlace() {
        let place = Places(context: ctx)
        place.location = "New Place"
        place.latitude = 0.0
        place.longitude = 0.0
        saveData()
    }
    /// This function `Delete place` instance
    func deletePlaces(_ idx: IndexSet) {
        var place:[Places] = []
        idx.forEach{
            place.append(places[$0])
        }
        deletePlace(place:place)
        ///deletePlace function in viewModel
    }
    
    
}
