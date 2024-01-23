//
//  Persistence.swift
//  FavouritePlaces
//
//  Created by Anuj Khurana on 26/4/2023.
//

import SwiftUI
import CoreData

/// to interact with core data
struct PersistenceHandler {
    static let shared = PersistenceHandler()
    let container: NSPersistentContainer
    init() {
        container = NSPersistentContainer(name:"Places")
        container.loadPersistentStores { _, error in
            if let e = error {
                fatalError("Error in load data \(e).")
            }
        }
    }
}
