import { createApp } from 'vue'
import App from './App.vue'
import { Quasar } from 'quasar'
import quasarUserOptions from './quasar-user-options'
import router from './router'
import store from './store'

createApp(App).use(store).use(router).use(router).use(Quasar, quasarUserOptions).mount('#app')
