//
//  RowView.swift
//  FavouritePlaces
//
//  Created by Anuj Khurana on 30/4/2023.
//

import SwiftUI


/// displays each row of the Places List on the the master with and includes an image icon plus the name of the place
/// - Parameters:
///   - place:An observed object representing a Place instance.
///   - image:A state variable holding the image associated with a landmark of the place.
struct RowView: View {
    @State var image = defaultImage
    @ObservedObject var place: Places
    
    var body: some View {
        HStack{
            image.frame(width: 50, height: 50).clipShape(Circle())
            Text(place.strLocation).font(.title2).fontWeight(.medium).padding(.leading)
        }
        .task {
            image = await place.getImage()
        }
    }
}
