//
//  FavouritePlacesApp.swift
//  FavouritePlaces
//
//  Created by Anuj Khurana on 26/4/2023.
//

import SwiftUI

@main
struct FavouritePlacesApp: App {
    var handler = PersistenceHandler.shared // for coredata interaction
    var body: some Scene {
        WindowGroup {
            ContentView().environment(\.managedObjectContext, handler.container.viewContext)
        }
    }
}
