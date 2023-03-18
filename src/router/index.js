import { createRouter, createWebHashHistory } from 'vue-router'
import HomeView from '../views/HomeView.vue'
import DeviceView from '../views/DeviceView.vue'


const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
  },
  {
    path: '/',
    name: 'device',
    component: DeviceView
  },
]

const router = createRouter({
  history: createWebHashHistory(),
  routes
})

export default router
